/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:50:45 by kamil             #+#    #+#             */
/*   Updated: 2024/12/09 15:45:09 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = gettime(MILISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	t_to_die = philo->data->time_to_die / 1e3;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_data	*table;

	table = (t_data *)data;
	while (!all_threads_running(&table->data_mutex,
			&table->threads_running_count, table->philo_nbr))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table->philo_nbr)
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->data_mutex, &table->end_simulation, true);
				write_status(DIED, table->philos + i);
			}
		}
	}
	return (NULL);
}
