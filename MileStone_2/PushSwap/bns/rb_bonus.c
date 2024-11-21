/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:29 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:17:29 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	rb(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sb[0];
	i = -1;
	while (++i < (d->sib - 1))
		d->sb[i] = d->sb[i + 1];
	d->sb[d->sib - 1] = temp;
}
