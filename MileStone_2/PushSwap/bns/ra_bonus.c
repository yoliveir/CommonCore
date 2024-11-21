/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:24 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:24 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	ra(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[0];
	i = -1;
	while (++i < (d->sia - 1))
		d->sa[i] = d->sa[i + 1];
	d->sa[d->sia - 1] = temp;
}
