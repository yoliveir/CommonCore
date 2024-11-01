/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:58:46 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:13 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*Toma como parámetro un nodo ’lst’ y libera la memoria del
contenido utilizando la función ’del’ dada como parámetro,
además de liberar el nodo. La memoria de ’next’ no debe liberarse.*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
