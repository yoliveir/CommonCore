/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:20:09 by kamil             #+#    #+#             */
/*   Updated: 2024/12/09 16:06:24 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static const char	*valid_input(const char *str)
{
	int	len;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Negative numbers are not accepted");
	if (!ft_isdigit(*str))
		error_exit("Invalid input: not a number");
	while (ft_isdigit(str[len]))
		len++;
	if (len > 10)
		error_exit("The value surpasses INT_MAX");
	return (str);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (ft_isdigit(*str))
	{
		num = (num * 10) + (*str++ - '0');
		if (num > INT_MAX)
			error_exit("The value surpasses INT_MAX");
	}
	return (num);
}

void	parse_input(t_data *data, char **av)
{
	data->philo_nbr = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1e3;
	data->time_to_eat = ft_atol(av[3]) * 1e3;
	data->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_sleep < 6e4
		|| data->time_to_eat < 6e4)
		error_exit("Use timestamps major than 60ms");
	if (av[5])
		data->meal_limit = ft_atol(av[5]);
	else
		data->meal_limit = -1;
}
