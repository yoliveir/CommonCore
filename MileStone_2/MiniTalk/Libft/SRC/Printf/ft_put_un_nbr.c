/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:09:59 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/29 19:07:57 by yurolive         ###   ########.fr       */
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

static void	ft_print_nb(unsigned int nb)
{
	if (nb > 9)
	{
		ft_print_nb(nb / 10);
		ft_putchar_fd((nb % 10) + '0', 1);
	}
	else
		ft_putchar_fd((nb % 10) + '0', 1);
}

int	ft_put_un_nbr(unsigned int nb)
{
	ft_print_nb(nb);
	return (ft_len_nbr(nb));
}

int	ft_putnbr_printf(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (ft_len_nbr(nb));
}

int	ft_putstr_printf(char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr_printf("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (ft_strlen(str));
}
