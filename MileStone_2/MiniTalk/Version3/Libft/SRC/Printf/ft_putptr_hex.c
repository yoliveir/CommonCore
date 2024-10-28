/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:17:42 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/21 13:59:56 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_len_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_print_ptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_print_ptr(nb / 16);
		ft_print_ptr(nb % 16);
	}
	else if (nb > 9)
		ft_putchar_fd(nb - 10 + 'a', 1);
	else
		ft_putchar_fd(nb + '0', 1);
}

int	ft_putptr_hex(unsigned long long nb)
{
	if (nb == 0)
		return (ft_putstr_printf("(nil)"));
	ft_putstr_printf("0x");
	ft_print_ptr(nb);
	return (ft_len_ptr(nb) + 2);
}
