/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:39:58 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/29 15:19:02 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#define TIMEOUT 5
#define SLEEP_TIME 500000

void	clean_global(void)
{
	g_client.client_activity = 0;
	if (g_client.msg.message != NULL)
	{
		write(2, "There was a problem with the last client\n", 42);
		free(g_client.msg.message);
	}
	ft_bzero(&g_client, sizeof(g_client));
	g_client.getting_header = 1;
}

int	check_clean_status(void)
{
	int	i;

	if (g_client.actual_pid == 0)
		return (sleep (1), 1);
	i = 0;
	while (i < TIMEOUT)
	{
		usleep(SLEEP_TIME);
		if (g_client.client_activity)
		{
			g_client.client_activity = 0;
			i = 0;
		}
		i++;
	}
	if (i == TIMEOUT)
		clean_global();
	return (0);
}

void	keep_server_up(void)
{
	while (1)
		check_clean_status();
}
