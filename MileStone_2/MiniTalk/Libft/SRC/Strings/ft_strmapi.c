/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:34:10 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:40:15 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*Applies the function f to each character of the
string s to create a new string (with malloc(3))
resulting from successive applications of f.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_strdup(s);
	if (!s || !f || !str)
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
