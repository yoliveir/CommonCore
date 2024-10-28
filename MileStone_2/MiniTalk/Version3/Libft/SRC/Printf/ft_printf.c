/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:27:40 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/21 13:51:07 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*
• %c Imprime un solo carácter.
• %s Imprime una string (como se define por defecto en C).
• %p El puntero void * dado como argumento se imprime en formato hexadecimal.
• %d Imprime un número decimal (base 10).
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
• % % para imprimir el símbolo del porcentaje.
*/
int	ft_handler_flags(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr_hex(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_printf(va_arg(args, int)));
	else if (format == 'u')
		return (ft_put_un_nbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			len += ft_handler_flags(args, str[i]);
		}
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
