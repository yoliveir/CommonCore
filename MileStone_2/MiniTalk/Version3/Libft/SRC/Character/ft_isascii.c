/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:07:48 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/18 11:41:54 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isascii function tests if a given character, in the current locale,*/
/*can be represented as a valid ASCII character.*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
