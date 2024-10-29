/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:15:42 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/29 19:08:14 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define _XOPEN_SOURCE 500
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "../Libft/libft.h"

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

typedef struct s_client
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*msg;
}	t_client;

typedef struct s_global
{
	int						pid;
	volatile sig_atomic_t	is_ready;
	volatile sig_atomic_t	ready_to_proceed;
}	t_global;

extern t_global	g_server;

void	parser(int argc, char **argv);
int		ping(int pid);

void	init_data(char **argv, t_client *data);
void	send_signal(pid_t pid, int signal);
void	send_signals(void *data, size_t bit_length, t_client *info);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_message(char *str, t_client *data);
void	ft_print_error(char *error_msg);

#endif