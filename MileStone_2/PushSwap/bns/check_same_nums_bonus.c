/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_same_nums_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:16:38 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:16:39 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

static int	ft_check(t_list *d, int num, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (d->sa[i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_same_nums(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (ft_check(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}
