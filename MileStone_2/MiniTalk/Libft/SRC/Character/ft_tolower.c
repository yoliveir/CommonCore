/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:20:03 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/17 16:09:54 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The tolower function takes an uppercase alphabet and */
/*convert it to a lowercase character.*/
int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		c += 'a' - 'A';
	}
	return (c);
}
