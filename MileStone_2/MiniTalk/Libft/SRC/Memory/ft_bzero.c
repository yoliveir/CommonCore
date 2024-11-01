/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:42:38 by yurolive          #+#    #+#             */
/*   Updated: 2024/09/18 11:42:38 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*The bzero function shall place n zero-valued bytes*/
/*in the area pointed to by s.*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
