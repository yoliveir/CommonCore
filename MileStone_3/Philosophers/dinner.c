/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:31:33 by kamil             #+#    #+#             */
/*   Updated: 2024/12/09 16:13:27 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo, bool pre)
{
	long	t_eat;
	long	t_think;
	long	t_sleep;

	if (!pre)
		write_status(THINKING, philo);
	if (philo->data->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think * 0.42, philo->data);
}

void	*lone_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILISECOND));
	increase_long(&philo->data->data_mutex,
		&philo->data->threads_running_count);
	write_status(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->data))
		usleep(100);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILISECOND));
	philo->nbr_meals++;
	write_status(EATING, philo);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->meal_limit > 0
		&& philo->nbr_meals == philo->data->meal_limit)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILISECOND));
	increase_long(&philo->data->data_mutex,
		&philo->data->threads_running_count);
	desynchro_philos(philo);
	while (!simulation_finished(philo->data))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		think(philo, false);
	}
	return (NULL);
}

void	dinner_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->meal_limit == 0)
		return ;
	if (data->philo_nbr == 1)
		safe_thread_handle(&data->philos[0].thread_id, lone_philo,
			&data->philos[0], CREATE);
	else
	{
		while (++i < data->philo_nbr)
			safe_thread_handle(&data->philos[i].thread_id, dinner_simulation,
				&data->philos[i], CREATE);
	}
	safe_thread_handle(&data->monitor, monitor_dinner, data, CREATE);
	data->start_simulation = gettime(MILISECOND);
	set_bool(&data->data_mutex, &data->all_threads_ready, true);
	i = -1;
	while (++i < data->philo_nbr)
		safe_thread_handle(&data->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&data->data_mutex, &data->end_simulation, true);
	safe_thread_handle(&data->monitor, NULL, NULL, JOIN);
}
