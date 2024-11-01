# Las Flags para compilar
FLAG = -Wall -Wextra -Werror

# Definición de Colores
RESET      = \033[0m
RED        = \033[31m 
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
CYAN       = \033[36m
MAGENTA    = \033[35m

# Los nombres de los ejecutables
SRV = server/server
CLN = client/client
SRV_BONUS = server_bonus/server
CLN_BONUS = client_bonus/client

# Librería externa
LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos fuente de client y server
SRV_SRC = server/main.c server/pong.c server/server_loop.c server/server.c
CLN_SRC = client/client.c client/main.c client/ping.c 
SRV_BONUS_SRC = server_bonus/main_bonus.c server_bonus/pong_bonus.c server_bonus/server_loop_bonus.c server_bonus/server_bonus.c
CLN_BONUS_SRC = client_bonus/client_bonus.c client_bonus/main_bonus.c client_bonus/ping_bonus.c 

# Archivos .o
SRV_OBJ = ${SRV_SRC:.c=.o}
CLN_OBJ = ${CLN_SRC:.c=.o}
SRV_BONUS_OBJ = ${SRV_BONUS_SRC:.c=.o}
CLN_BONUS_OBJ = ${CLN_BONUS_SRC:.c=.o}

# Compilación normal
all: ${LIBFT} check_header ${SRV} ${CLN}

# Construir la librería antes de compilar los objetivos
${LIBFT}:
	@echo "${CYAN}=========================================${RESET}"
	@echo "${CYAN}Building libft...${RESET}"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "${GREEN}Libft built successfully.${RESET}"
	@echo "${CYAN}=========================================${RESET}"

# Verificar si se debe mostrar el encabezado
check_header:
	@if [ ! -f ${SRV} ] || [ ! -f ${CLN} ]; then \
		echo "${MAGENTA}"; \
		echo "========================================="; \
		echo "          MINITALK - BUILD PROCESS       "; \
		echo "========================================="; \
		echo "${RESET}"; \
	else \
		echo "${RED}=========================================${RESET}"; \
		echo "${RED}   Make: Nothing to be done for 'all'${RESET}"; \
		echo "${RED}=========================================${RESET}"; \
		exit 0; \
	fi

# Crear server a partir de los archivos .o
${SRV}: ${SRV_OBJ} ${LIBFT}
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${SRV}...${RESET}"
	@cc ${SRV_OBJ} ${LIBFT} -o $@
	@echo "${GREEN}${SRV} created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Crear client a partir de los archivos .o
${CLN}: ${CLN_OBJ} ${LIBFT}
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building ${CLN}...${RESET}"
	@cc ${CLN_OBJ} ${LIBFT} -o $@
	@echo "${GREEN}${CLN} created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Compilación de archivos .o
%.o: %.c
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Compiling $<...${RESET}"
	@cc ${FLAG} -Iserver -Iclient -I$(LIBFT_DIR) -c $< -o $@
	@echo "${GREEN}Compiled $< into $@${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Regla bonus
bonus: fclean ${LIBFT} ${SRV_BONUS_OBJ} ${CLN_BONUS_OBJ}
	@echo "${YELLOW}=========================================${RESET}"
	@echo "${YELLOW}Building bonus server and client...${RESET}"
	@cc ${SRV_BONUS_OBJ} ${LIBFT} -o ${SRV_BONUS}
	@cc ${CLN_BONUS_OBJ} ${LIBFT} -o ${CLN_BONUS}
	@echo "${GREEN}Bonus server and client created${RESET}"
	@echo "${YELLOW}=========================================${RESET}"
	@echo ""

# Borra los archivos .o
clean:
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning object files...${RESET}"
	@rm -f ${CLN_OBJ} ${SRV_OBJ} ${CLN_BONUS_OBJ} ${SRV_BONUS_OBJ}
	@echo "${GREEN}All object files cleaned.${RESET}"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""

# Borra los archivos .o y el "Programa"
fclean: clean
	@echo "${MAGENTA}=========================================${RESET}"
	@echo "${YELLOW}Cleaning executables...${RESET}"
	@rm -f ${SRV} ${CLN} ${SRV_BONUS} ${CLN_BONUS}
	@echo "${GREEN}Executables cleaned.${RESET}"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "${MAGENTA}=========================================${RESET}"
	@echo ""

# Borra el "Programa" y recompila
re: fclean all

# Indica a Make que no son archivos reales, sino nombres de objetivos
.PHONY: all clean fclean re check_header bonus
