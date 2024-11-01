/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:49:01 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:45 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*Utilizando malloc(3, genera una string que
represente el valor entero recibido como argumento.
Los números negativos tienen que gestionarse.*/

static void	ft_isnegat(size_t size, char *str, long nbr)
{
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	size = 0;
	nbr = n;
	if (n <= 0)
	{
		nbr = -nbr;
		size = 1;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!(str))
		return (0);
	ft_isnegat(size, str, nbr);
	return (str);
}
