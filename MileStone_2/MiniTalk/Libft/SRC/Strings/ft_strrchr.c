/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:11:32 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:40:23 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*The function strrchr searches for the last occurrence of the*/
/*character c in the string pointed to, by the argument str.*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
