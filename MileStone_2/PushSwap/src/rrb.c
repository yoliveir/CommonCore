/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartin <gemartin@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:55:25 by gemartin          #+#    #+#             */
/*   Updated: 2022/04/11 15:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	rrb(t_list *d)
{
	int	i;
	int	j;

	i = d->sib - 1;
	j = 0;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrb\n", 4);
}
