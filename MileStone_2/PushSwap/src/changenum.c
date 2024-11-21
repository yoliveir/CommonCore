/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changenum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:10:28 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:10:30 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	changenum(t_list *d)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < d->argc)
	{
		if (d->sa[j] != d->sp[i])
			i++;
		else
		{
			d->sa[j] = i;
			j++;
			i = 0;
		}
	}
}
