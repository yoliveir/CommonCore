# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 15:05:09 by yurolive          #+#    #+#              #
#    Updated: 2024/12/11 15:31:14 by yurolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = fractol

# Definicion de Colores
RESET      = \033[0m
RED        = \033[31m 
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
CYAN       = \033[36m
MAGENTA    = \033[35m

# Compilador y opciones de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directorios
MLX_DIR = minilibx-linux
INCLUDE_DIR = .

# Librerías
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext
LIBS = $(MLX_LIB)

# Archivos fuente y objetos
SRCS = events.c \
		init.c \
		main.c \
		math_utils.c \
		render.c \
		string_utils.c
		
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS)
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${NAME}...${RESET}"
	@make -C $(MLX_DIR)
	@echo "${YELLOW}=========================================${RESET}"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "${GREEN}${NAME} created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Regla para compilar los archivos fuente a objetos
%.o: %.c
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $<
	@echo "${GREEN}Compiled $< into $@${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Limpiar los objetos
clean:
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning object files...${RESET}"
	@rm -f $(OBJS)
	@echo "${GREEN}All object files cleaned.${RESET}"
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""

# Limpiar los objetos y el ejecutable
fclean: clean
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning executables...${RESET}"
	@make clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@echo "${GREEN}Executables cleaned.${RESET}"
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""

# Reconstruir el proyecto
re: fclean all

# Indica a Make que no son archivos reales, sino nombres de objetivos, Esto evita conflictos si existieran archivos con esos mismos nombres.
.PHONY:	all clean fclean re