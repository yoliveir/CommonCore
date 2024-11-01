/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:10:12 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/21 13:52:23 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_len_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb = -nb;
		len++;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (ft_len_nbr(nb));
}
