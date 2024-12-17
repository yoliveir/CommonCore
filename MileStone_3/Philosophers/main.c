/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:09:00 by kamil             #+#    #+#             */
/*   Updated: 2024/12/10 11:07:38 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		parse_input(&data, av);
		data_init(&data);
		dinner_start(&data);
		clean_data(&data);
	}
	else
		error_exit("Wrong input\nnumber_of_philosophers time_to_die time_to_eat"
			"time_to_sleep [number_of_times_each_philosopher_must_eat]");
}
