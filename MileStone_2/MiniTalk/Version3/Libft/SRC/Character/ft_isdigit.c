/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:01:42 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/18 11:41:51 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The isdigit function checks whether a character is*/
/*numeric character (0-9) or not.*/
int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
	{
		return (1);
	}
	return (0);
}
