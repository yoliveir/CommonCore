/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:46 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:46 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	rrb(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sb[d->sib - 1];
	i = d->sib - 1;
	while (--i >= 0)
		d->sb[i + 1] = d->sb[i];
	d->sb[0] = temp;
}
