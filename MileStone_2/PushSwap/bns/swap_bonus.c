/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:18:21 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/11 16:18:21 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap_bonus.h"

void	swap(int *argv1, int *argv2)
{
	int	temp;

	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}
