/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:50:42 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/28 16:50:42 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/*
------------------
	STATES
------------------
	0 INIT
	1 ERR
	2 Found Digit
------------------
	[ *  D ]
------------------
*/

int	get_state(int x, int y)
{
	const int	states[][2] = {\
	{1, 2}, \
	{1, 1}, \
	{1, 2}, \
	};

	return (states[x][y]);
}

int	choose_state(int state, char c)
{
	int	pos;

	pos = 0;
	if (ft_isdigit(c))
		pos = 1;
	state = get_state(state, pos);
	return (state);
}

void	evaluate(const char *str)
{
	int	i;
	int	state;

	i = 0;
	state = 0;
	while (str[i])
	{
		state = choose_state(state, str[i]);
		i++;
	}
	if (state < 2)
		ft_print_error((char *)str);
}

void	parser(int argc, char **argv)
{
	if (argc != 3)
		ft_print_error(USAGE);
	evaluate(argv[1]);
}