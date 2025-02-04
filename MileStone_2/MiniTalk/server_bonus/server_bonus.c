/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:39:14 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/30 16:44:48 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static int	get_bit_value(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	return (1);
}

void	memory_reserve_to_store_signals(void)
{
	ft_printf("SIZE_MSG: [%d]\n", g_client.msg.size_message);
	g_client.msg.message = malloc((g_client.msg.size_message + 1) * 1);
	if (g_client.msg.message == NULL)
		ft_print_error("Malloc_failed");
	g_client.getting_header = 0;
	g_client.getting_msg = 1;
	g_client.sig_count = 0;
}

void	handle_header(int signum)
{
	const int	bit_value = get_bit_value(signum);

	if (g_client.sig_count < HEADER_SIZE)
	{
		g_client.msg.size_message |= \
			(bit_value << (HEADER_SIZE - 1 - g_client.sig_count));
		g_client.sig_count++;
	}
	if (g_client.sig_count == HEADER_SIZE)
		memory_reserve_to_store_signals();
}

static void	print_msg(void)
{
	write(1, HEADER_MESSAGE, 18);
	write(1, g_client.msg.message, g_client.msg.size_message);
	write(1, "\n", 1);
}

void	handle_msg(int signum)
{
	const int	bit_value = get_bit_value(signum);

	if (g_client.sig_count % 8 < 8)
	{
		g_client.char_value |= (bit_value << (7 - (g_client.sig_count % 8)));
		(g_client.sig_count)++;
	}
	if (g_client.sig_count % 8 == 0)
	{
		g_client.msg.message[g_client.msg_pos] = g_client.char_value;
		g_client.char_value = 0;
		g_client.msg_pos++;
	}
	if (g_client.sig_count / 8 == g_client.msg.size_message)
	{
		print_msg();
		kill(g_client.client_pid, SIGUSR1);
		free(g_client.msg.message);
		g_client.msg.message = NULL;
		ft_bzero(&g_client, sizeof(g_client));
		g_client.getting_header = 1;
	}
}
