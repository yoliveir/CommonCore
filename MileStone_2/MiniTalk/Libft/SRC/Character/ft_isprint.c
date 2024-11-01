/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:10:38 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/18 11:41:48 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isprint function checks whether a character is*/
/*a printable character or not.*/
int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
	{
		return (1);
	}
	return (0);
}
