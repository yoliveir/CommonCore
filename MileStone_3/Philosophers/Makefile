# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamil <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 10:49:52 by kamil             #+#    #+#              #
#    Updated: 2024/12/09 10:49:55 by kamil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror

# Project files
SRCS    := dinner.c getters_setters.c init.c main.c monitor.c parsing.c safe_funcs.c synchro_utils.c utils.c write.c
OBJS    := $(SRCS:.c=.o)
NAME    := philo

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
