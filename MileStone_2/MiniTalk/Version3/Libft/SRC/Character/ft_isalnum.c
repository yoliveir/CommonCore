/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:04:43 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/18 11:42:14 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalnum function checks whether the argument passed is*/
/* an alphanumeric character (alphabet or number) or not. */
int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1);
	}
	else if (c > 47 && c < 58)
	{
		return (1);
	}
	return (0);
}
