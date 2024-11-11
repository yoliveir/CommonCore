/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordernums_peq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:12:36 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:21:28 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	ordernums_peq_sb(t_list *d)
{
	while (d->sib > 0)
	{
		if (d->sb[0] == d->lsp - 1)
		{
			pa(d);
			d->control = 1;
		}
		if (d->sb[0] == d->lsp)
		{
			pa(d);
			d->lsp--;
			if (d->control == 1)
			{
				d->lsp--;
				d->control = 0;
				sa(d->sa);
			}
		}
		else
			rb(d);
	}
}

void	ordernums_peq3(t_list *d, int i)
{
	while (i >= 0)
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	ordernums_peq_sb(d);
}

void	ordernums_peq2(t_list *d)
{
	int	i;

	i = d->lsp;
	while (d->sib < 1)
	{
		if (d->sa[0] == i)
			pb(d);
		else
			ra(d);
	}
}

void	ordernums_peq(t_list *d)
{
	int	i;

	i = d->lsp;
	while (d->sib <= (d->argc / 2))
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	ordernums_peq_sb(d);
	ordernums_peq3(d, i);
}
