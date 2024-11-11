/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:40 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:41 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	rra(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[d->sia - 1];
	i = d->sia - 1;
	while (--i >= 0)
		d->sa[i + 1] = d->sa[i];
	d->sa[0] = temp;
}
