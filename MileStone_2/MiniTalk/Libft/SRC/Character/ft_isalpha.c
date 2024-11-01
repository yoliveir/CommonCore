/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:31:04 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/18 11:41:58 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isalpha function checks whether a character is an alphabet or not.*/
int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1);
	}
	return (0);
}
