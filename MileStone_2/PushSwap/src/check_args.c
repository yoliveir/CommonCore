/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:10:37 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/12 19:58:06 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	add_name(char ***args, int *argc)
{
	char	**new_args;
	int		i;

	i = -1;
	while (++i < *argc)
	{
		if (check_num((*args)[i]) == -1 || (*args)[i][0] == '\0')
			return (-1);
	}
	new_args = malloc(sizeof(char *) * (*argc + 2));
	if (!new_args)
		return (-1);
	new_args[0] = ft_strdup("push_swap");
	if (!new_args[0])
		return (free(new_args), -1);
	i = 0;
	while (i < *argc)
	{
		new_args[i + 1] = (*args)[i];
		i++;
	}
	new_args[*argc + 1] = NULL;
	free(*args);
	return (*args = new_args, *argc += 1, 0);
}

int	check_args(char ***args, int *argc)
{
	char	**split_args;
	int		i;

	if (*argc == 2)
	{
		split_args = ft_split((*args)[1], ' ');
		if (!split_args)
			return (-1);
		*args = split_args;
		*argc = 0;
		while (split_args[*argc])
			(*argc)++;
		if (add_name(args, argc) == -1)
			return (ft_free_split(split_args), -1);
		return (0);
	}
	i = 0;
	while (++i < *argc)
	{
		if (check_num((*args)[i]) == -1 || (*args)[i][0] == '\0')
			return (-1);
	}
	return (0);
}
