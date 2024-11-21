/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:10:58 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:11:04 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	check_order(t_list *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < d->argc - 1)
	{
		if (d->sa[j] < d->sa[j + 1])
			i++;
		j++;
	}
	if (i == j)
		return (-1);
	else
		return (0);
}
