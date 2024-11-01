/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:14:57 by yuolivei          #+#    #+#             */
/*   Updated: 2024/09/17 16:09:38 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The toupper function takes an lowercase alphabet and */
/*convert it to a uppercase character.*/
int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		c -= 'a' - 'A';
	}
	return (c);
}
