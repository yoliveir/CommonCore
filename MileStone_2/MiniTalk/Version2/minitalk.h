/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:38:41 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/25 16:33:37 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 500
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

// Estructura para el estado del servidor
typedef struct {
    pid_t current_client_pid; // PID del cliente actual
    int bit_index;            // Índice de bits recibidos
    char bits[8];             // Almacena los bits recibidos
    char *message;            // Almacena la cadena completa recibida
    int message_length;       // Longitud actual del mensaje
    int message_capacity;     // Capacidad de la cadena
} ServerState;

extern ServerState state;

// Funciones comunes
int ft_atoi(const char *str);
void conv_bin(char *s, int pidserv);
void ft_putchar(int c);
void ft_putnbr(int num);

// Funciones del servidor
void conv_txt();
void alm_bin(int sig, siginfo_t *info, void *context);
void init_server_state();

#endif // MINITALK