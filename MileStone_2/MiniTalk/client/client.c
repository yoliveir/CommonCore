/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:29:24 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/29 14:59:55 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_data(char **argv, t_client *data)
{
	ft_memset(data, 0, sizeof(t_client));
	data->server_pid = ft_atoi(argv[1]);
	data->client_pid = getpid();
	ft_printf("PID CLIENT %d\n", data->client_pid);
	data->msg = argv[2];
	if (data->server_pid == 0)
		ft_print_error(BAD_SIGNAL);
}

void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal))
		ft_print_error("Signal sending failed.");
}

void	send_signals(void *data, size_t bit_length, t_client *info)
{
	unsigned long long	value;
	int					i;

	value = 0;
	if (bit_length == 8)
		value = *((unsigned char *)data);
	else if (bit_length == 32)
		value = *((unsigned int *)data);
	i = bit_length - 1;
	while (i >= 0)
	{
		if (value & (1ULL << i))
			send_signal(info->server_pid, SIGUSR2);
		else
			send_signal(info->server_pid, SIGUSR1);
		i--;
		while (!g_server.ready_to_proceed)
			usleep(100);
		g_server.ready_to_proceed = 0;
	}
}

void	send_message(char *str, t_client *data)
{
	int	i;

	i = 0;
	while (str[i])
		send_signals(&str[i++], 8, data);
}
