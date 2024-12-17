/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:08:35 by kamil             #+#    #+#             */
/*   Updated: 2024/12/09 16:15:33 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->data->philo_nbr;
	philo->first_fork = &forks[(position + 1) % philo_nbr];
	philo->second_fork = &forks[position];
	if (philo->id % 2 == 0)
	{
		philo->second_fork = &forks[position];
		philo->first_fork = &forks[(position + 1) % philo_nbr];
	}
}

static void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->philo_nbr)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->nbr_meals = 0;
		philo->data = data;
		safe_mutex_handle(&philo->philo_mutex, INIT);
		assign_forks(philo, data->forks, i);
	}
}

void	data_init(t_data *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	data->all_threads_ready = false;
	data->threads_running_count = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->philo_nbr);
	safe_mutex_handle(&data->data_mutex, INIT);
	data->forks = safe_malloc(sizeof(t_fork) * data->philo_nbr);
	while (++i < data->philo_nbr)
	{
		safe_mutex_handle(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
	philo_init(data);
}
