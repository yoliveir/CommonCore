# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:55:41 by yurolive          #+#    #+#              #
#    Updated: 2024/10/21 14:16:10 by yurolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Las Flags para compilar
FLAG = -Wall -Wextra -Werror

# Definicion de Colores
RESET      = \033[0m
RED        = \033[31m 
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
CYAN       = \033[36m
MAGENTA    = \033[35m

# El nombre del "Programa"
NAME = libft.a

# Los Archivos "librerias" .c (dentro de la carpeta SRC)
SRC = SRC/Character/ft_isalpha.c \
		SRC/Character/ft_isdigit.c \
		SRC/Character/ft_isalnum.c \
		SRC/Character/ft_isascii.c \
		SRC/Character/ft_isprint.c \
		SRC/Strings/ft_strlen.c \
		SRC/Strings/ft_strlcpy.c \
		SRC/Strings/ft_strlcat.c \
		SRC/Strings/ft_strncmp.c \
		SRC/Strings/ft_atoi.c \
		SRC/Character/ft_tolower.c \
		SRC/Character/ft_toupper.c \
		SRC/Memory/ft_memset.c \
		SRC/Memory/ft_bzero.c \
		SRC/Memory/ft_memmove.c \
		SRC/Memory/ft_memcpy.c \
		SRC/Strings/ft_strnstr.c \
		SRC/Strings/ft_strchr.c \
		SRC/Strings/ft_strrchr.c \
		SRC/Memory/ft_memchr.c \
		SRC/Memory/ft_memcmp.c \
		SRC/Memory/ft_calloc.c \
		SRC/Strings/ft_strdup.c \
		SRC/Strings/ft_substr.c \
		SRC/Strings/ft_strjoin.c \
		SRC/Strings/ft_strtrim.c \
		SRC/Character/ft_putchar_fd.c \
		SRC/Strings/ft_putstr_fd.c \
		SRC/Strings/ft_putendl_fd.c \
		SRC/Strings/ft_putnbr_fd.c \
		SRC/Strings/ft_strmapi.c \
		SRC/Strings/ft_split.c \
		SRC/Strings/ft_itoa.c \
		SRC/Strings/ft_striteri.c \
		SRC/Lists/ft_lstnew_bonus.c \
		SRC/Lists/ft_lstadd_front_bonus.c \
		SRC/Lists/ft_lstsize_bonus.c \
		SRC/Lists/ft_lstlast_bonus.c \
		SRC/Lists/ft_lstadd_back_bonus.c \
		SRC/Lists/ft_lstdelone_bonus.c \
		SRC/Lists/ft_lstclear_bonus.c \
		SRC/Lists/ft_lstiter_bonus.c \
		SRC/Lists/ft_lstmap_bonus.c \
		SRC/GNL/get_next_line.c \
		SRC/GNL/get_next_line_utils.c \
		SRC/Printf/ft_printf.c \
		SRC/Printf/ft_put_hex.c \
		SRC/Printf/ft_put_un_nbr.c \
		SRC/Printf/ft_putnbr_printf.c \
		SRC/Printf/ft_putptr_hex.c

# Los Archivos "librerias" .o (guárdalos en la carpeta OBJ)
OBJ = $(SRC:%.c=OBJ/%.o)

# Se refiere a lo ejecutable
all: check_header ${NAME}

# Verificar si se debe mostrar el encabezado
check_header:
	@if [ ! -f ${NAME} ]; then \
		echo "${MAGENTA}"; \
		echo "========================================="; \
		echo "          LIBFT - BUILD PROCESS       "; \
		echo "========================================="; \
		echo "${RESET}"; \
	else \
		echo "${RED}=========================================${RESET}"; \
		echo "${RED}   Make: Nothing to be done for 'all'${RESET}"; \
		echo "${RED}=========================================${RESET}"; \
		exit 0; \
	fi

# Creo el "Programa" a partir de los archivos .o
${NAME}: ${OBJ}
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${NAME}...${RESET}"
	@ar rcs ${NAME} ${OBJ}
	@echo "${GREEN}${NAME} created and indexed${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""
	
# Crear los archivos .o (coloca los .o en la carpeta OBJ)
OBJ/%.o: %.c
	@mkdir -p $(dir $@)   # Crea las carpetas necesarias en OBJ
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Compiling $<...${RESET}"
	@gcc ${FLAG} -c $< -o $@
	@echo "${GREEN}Compiled $< into $@${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""
	
# Borra los archivos .o
clean:
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning object files...${RESET}"
	@rm -f ${OBJ}
	@echo "${GREEN}All object files cleaned.${RESET}"
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""
	
# Borra los archivos .o y el "Programa"
fclean: clean
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning executables...${RESET}"
	@rm -f ${NAME}
	@echo "${GREEN}Executables cleaned.${RESET}"
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""
	
# Borra el "Programa" y recompila
re: fclean all

# Indica a Make que no son archivos reales, sino nombres de objetivos, Esto evita conflictos si existieran archivos con esos mismos nombres.
.PHONY:	all clean fclean re check_header