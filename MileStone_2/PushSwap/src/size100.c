/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:14:50 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:14:51 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	size100(t_list *d)
{
	d->lsp = d->argc - 1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 4;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sortnum(d);
	changenum(d);
	if (d->argc >= 20)
		ordernums(d);
	else
		ordernums_peq(d);
}
