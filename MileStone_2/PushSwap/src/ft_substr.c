/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:12:25 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:12:26 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*copia;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		copia = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		copia = malloc(sizeof(char) * (len + 1));
	if (!copia)
		return (0);
	while (start < ft_strlen(s) && i < len && s[start])
	{
		copia[i] = s[start];
		i++;
		start++;
	}
	copia[i] = '\0';
	return (copia);
}
