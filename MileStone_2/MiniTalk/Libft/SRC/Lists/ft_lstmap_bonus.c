/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:13:15 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:19 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo.
Crea una lista resultante de la aplicación correcta y sucesiva de la función
’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el contenido de
un nodo, si hace falta.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*curr;
	t_list	*new;
	void	*aux;

	if (!f || !del || !lst)
		return (0);
	first = 0;
	curr = lst;
	while (curr)
	{
		aux = f(curr->content);
		new = ft_lstnew(aux);
		if (!new)
		{
			free(aux);
			ft_lstclear(&first, del);
			return (0);
		}
		ft_lstadd_back(&first, new);
		curr = curr->next;
	}
	return (first);
}
