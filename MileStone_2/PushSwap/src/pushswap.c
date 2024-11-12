/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:13:20 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/12 19:38:12 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int		arg_to_int(t_list *d, int arc, char **args);
int		ft_choose_size(int arc, t_list *d);
int		init_data(t_list *d, int argc);

int	main(int arc, char **args)
{
	t_list	*d;

	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_args(&args, &arc) == -1)
		ft_free(d);
	if (init_data(d, arc) == -1)
		ft_free(d);
	if (arg_to_int(d, arc, args) == -1)
	{
		ft_free(d);
		return (0);
	}
	if (check_order(d) == -1)
		ft_free2(d);
	if (ft_choose_size(arc, d) == -1)
		ft_free(d);
	ft_free2(d);
	return (0);
}

int	ft_choose_size(int arc, t_list *d)
{
	if (check_same_nums(d) == -1)
		return (-1);
	else
	{
		if (arc == 3 || arc == 4)
			size3(d->sa, d);
		if (arc < 7 && arc > 4)
			size5(d->sa, d);
		if (arc < 102 && arc > 6)
			size100(d);
		if (arc > 101)
			size500(d);
	}
	return (0);
}

int	arg_to_int(t_list *d, int arc, char **args)
{
	int	i;

	i = 0;
	while (i != arc - 1)
	{
		if (check_num(args[i + 1]) == -1)
			return (-1);
		d->sa[i] = ft_atoi(args[i + 1], d);
		if (d->atoierror == 1)
			return (-1);
		d->sp[i] = ft_atoi(args[i + 1], d);
		i++;
	}
	return (0);
}

int	init_data(t_list *d, int argc)
{
	d->sa = malloc(sizeof(int) * d->argc);
	if (!d->sa)
		return (free(d), -1);
	d->sp = malloc(sizeof(int) * d->argc);
	if (!d->sp)
	{
		free(d->sa);
		return (free(d), -1);
	}
	d->sb = malloc(sizeof(int) * d->argc);
	if (!d->sb)
	{
		free(d->sp);
		free(d->sa);
		free(d);
		return (-1);
	}
	d->argc = argc - 1;
	d->error = 0;
	d->sia = d->argc;
	d->sib = 0;
	d->sip = d->argc;
	return (0);
}
