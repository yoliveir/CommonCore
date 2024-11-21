/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:15 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:17 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	pb(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[0];
	i = -1;
	while (++i < (d->sia - 1))
		d->sa[i] = d->sa[i + 1];
	d->sia = d->sia - 1;
	i = d->sib;
	d->sib = d->sib + 1;
	while (--i >= 0)
		d->sb[i + 1] = d->sb[i];
	d->sb[0] = temp;
}
