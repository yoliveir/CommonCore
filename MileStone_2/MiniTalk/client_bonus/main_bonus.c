/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:29:44 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/30 16:43:57 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

t_global	g_server;

void	parser(int argc, char **argv)
{
	char	*str;
	int		i;

	str = argv[1];
	i = 0;
	if (argc != 3)
		ft_print_error(USAGE);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_print_error((char *)str);
		i++;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context, (void)info;
	if (signum == SIGUSR2)
		g_server.ready_to_proceed = 1;
	else if (signum == SIGUSR1)
		ft_print_error("\rThe Mesage was received by the server.");
}

int	main(int argc, char **argv)
{
	t_client			data;
	int					msg_len;
	struct sigaction	sa;
	sigset_t			sigset;

	parser(argc, argv);
	init_data(argv, &data);
	if (ping(data.server_pid) == 0)
		return (0);
	msg_len = ft_strlen(argv[2]);
	ft_printf("MSG_LEN: [%d] Bytes\n", msg_len);
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sa.sa_mask = sigset;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_signals(&msg_len, 32, &data);
	send_message(data.msg, &data);
	return (0);
}
