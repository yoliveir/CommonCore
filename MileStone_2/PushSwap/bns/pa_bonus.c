/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:08 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:08 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	pa(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sb[0];
	i = -1;
	while (++i < (d->sib - 1))
		d->sb[i] = d->sb[i + 1];
	d->sib = d->sib - 1;
	i = d->sia;
	d->sia = d->sia + 1;
	while (--i >= 0)
		d->sa[i + 1] = d->sa[i];
	d->sa[0] = temp;
}
