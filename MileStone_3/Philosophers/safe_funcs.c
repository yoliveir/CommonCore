/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:10:14 by kamil             #+#    #+#             */
/*   Updated: 2024/12/10 11:09:25 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Malloc error");
	return (ret);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_exit("the mutex value is invalid");
	else if (EINVAL == status && INIT == opcode)
		error_exit("The attr value is invalid");
	else if (EDEADLK == status)
		error_exit("A deadlock would occur if"
			"the thread blocked waiting for mutex");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex");
	else if (ENOMEM == status)
		error_exit("The process cannot allocate enough"
			"memory to create another mutex");
	else if (EBUSY == status && LOCK == opcode)
		error_exit("Mutex is already locked (trylock failed)");
}
/* 
	MUTEX SAFE
	init
	destroy
	lock 
	unlock
*/

void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Wrong opcode for mutex handle");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("No resources to create another thread");
	else if (status == EPERM)
		error_exit("The caller does not have appropiate permission\n");
	else if (status == EINVAL && opcode == CREATE)
		error_exit("The value specified by attr is invalid");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit("The value specified by thread is not joinable\n");
	else if (status == ESRCH)
		error_exit("No thread could be found corresponding"
			"to that, specified by the given thread ID, thread");
	else if (status == EDEADLK)
		error_exit("A deadlock was detected or the"
			"value of thread specifies the calling thread");
}

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
		t_opcode opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("Wrong code for thread handle:\n"
			"use <Create> <Join> <Detach>");
}
