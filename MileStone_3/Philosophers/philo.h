/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:20:32 by kamil             #+#    #+#             */
/*   Updated: 2024/12/10 11:01:54 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}						t_time_code;

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				nbr_meals;
	bool				full;
	long				last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	t_mtx				philo_mutex;
	t_data				*data;
}						t_philo;

struct					s_data
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_sleep;
	long				time_to_eat;
	long				meal_limit;
	long				start_simulation;
	bool				end_simulation;
	bool				all_threads_ready;
	long				threads_running_count;
	t_mtx				data_mutex;
	t_mtx				write_mutex;
	t_fork				*forks;
	t_philo				*philos;
	pthread_t			monitor;
};

// SYNCHRO UTILS
void					desynchro_philos(t_philo *philo);
bool					all_threads_running(t_mtx *mutex, long *threads,
							long philo_nbr);
void					increase_long(t_mtx *mutex, long *value);
void					wait_all_threads(t_data *data);
// UTILS
void					error_exit(const char *error);
void					precise_usleep(long usec, t_data *data);
long					gettime(t_time_code time_code);
void					write_status(t_philo_status status, t_philo *philo);
void					clean_data(t_data *data);
// INIT
void					data_init(t_data *data);
void					dinner_start(t_data *data);
// PARSING
void					parse_input(t_data *data, char **av);
// SAFE FUNCS
void					*safe_malloc(size_t bytes);
void					safe_thread_handle(pthread_t *thread,
							void *(*foo)(void *),
							void *data, t_opcode opcode);
void					safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
// SETTERS AND GETTERS
void					set_bool(t_mtx *mutex, bool *dest, bool value);
bool					get_bool(t_mtx *mutex, bool *value);
void					set_long(t_mtx *mutex, long *dest, long value);
long					get_long(t_mtx *mutex, long *value);
bool					simulation_finished(t_data *data);
// MONITOR
void					*monitor_dinner(void *data);
// SIMULATION
void					think(t_philo *philo, bool pre);
#endif
