/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordernums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:12:44 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:12:44 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	calc(t_list *d)
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
		if (d->control == 2)
		{
			d->lsp = d->lsp - 2;
			d->control = 0;
			sa(d->sa);
			rra(d);
		}
	}
	else
		rb(d);
}

int	check_mov(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sib - 1)
	{
		if (d->sb[i] == d->lsp)
			break ;
		i++;
	}
	if ((d->sib / 2) - i >= 0)
		return (0);
	else
		return (-1);
}

void	ordernums_sb_rotate(t_list *d)
{
	if (d->sb[0] == d->lsp -2 && d->control == 1)
	{
		pa(d);
		ra(d);
		d->control = 2;
	}
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
		rrb(d);
}

void	ordernums_sb(t_list *d)
{
	while (d->sia < d->argc)
	{
		if (d->sb[0] == d->lsp && d->control == 0)
		{
			pa(d);
			d->lsp--;
		}
		if (d->sb[0] == d->lsp -2 && d->control == 1)
		{
			pa(d);
			ra(d);
			d->control = 2;
		}
		if (check_mov(d) == -1)
			ordernums_sb_rotate(d);
		else
			calc(d);
	}
}

void	ordernums(t_list *d)
{
	d->arguments = (d->argc / d->cont) * (d->percentage);
	if (d->percentage == d->cont)
		d->arguments = d->argmax - 3;
	while (d->sib < d->arguments && d->percentage <= d->cont)
	{
		if (d->sa[0] < d->arguments)
		{
			pb(d);
			if (d->sb[0] > d->arguments - d->size_block && d->sib > 1)
				rb(d);
		}
		else
			ra(d);
	}
	d->percentage++;
	if (d->sib == d->argmax - 3)
	{
		size3(d->sa, d);
		d->lsp = d->lsp - 3;
	}
	if (d->percentage <= d->cont)
		ordernums(d);
	while (d->percentage-- > 0)
		ordernums_sb(d);
}
