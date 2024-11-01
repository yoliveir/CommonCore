/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:38:10 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/29 18:00:03 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define _XOPEN_SOURCE 500
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "../Libft/libft.h"

# define HEADER_SIZE 32
# define SIGNAL_RECEIVED SIGUSR2

# define HEADER_MESSAGE "\033[4mMessage:\033[0m\n"

typedef struct s_msg
{
	int		size_message;
	char	*message;
}	t_msg;

typedef struct s_global
{
	volatile sig_atomic_t	client_pid;
	volatile sig_atomic_t	actual_pid;
	volatile sig_atomic_t	getting_header;
	volatile sig_atomic_t	getting_msg;
	volatile sig_atomic_t	client_activity;
	volatile sig_atomic_t	sig_count;
	char					char_value;
	volatile sig_atomic_t	msg_pos;
	t_msg					msg;
}	t_global;

extern t_global	g_client;

void	keep_server_up(void);
int		pong(int pid);
void	handle_msg(int signum);
void	handle_header(int signum);
void	ft_print_error(char *error_msg);
#endif