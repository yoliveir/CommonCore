#include "minitalk.h"

char bits_to_char(const char *bits) {
    char result = 0;
    for (int i = 0; i < 8; i++)
        result = (result << 1) | (bits[i] - '0');
    return result;
}

void alm_bin(int sig, siginfo_t *info, void *context)
{
    if (state.current_client_pid == 0) {
        // Primer cliente que se conecta
        state.current_client_pid = info->si_pid;
    } else if (state.current_client_pid != info->si_pid) {
        // Si el PID no coincide, ignorar la señal
        return;
    }
    printf("Bit recibido: %d\n", info->si_pid);
    if (sig == SIGUSR1)
        state.bits[state.bit_index] = '1';
    else if (sig == SIGUSR2)
        state.bits[state.bit_index] = '0';

    state.bit_index++;
    if (state.bit_index == 8)
    {
        state.bit_index = 0;

        // Convertir los bits a un carácter
        char result = 0;
        for (int i = 0; i < 8; i++)
        {
            result <<= 1;
            if (state.bits[i] == '1')
                result |= 1;
        }

        if (result == '\0') {
            printf("Carácter recibido: %c : %d\n", result, info->si_pid); // Si se recibe un byte nulo, significa fin de mensaje
            conv_txt(); // Imprimir la cadena completa
            free(state.message); // Liberar la memoria
            init_server_state(); // Reiniciar el estado
        } else {
            // Agregar el carácter recibido al final de la cadena
            if (state.message_length + 1 >= state.message_capacity) {
                // Aumentar la capacidad de la cadena
                state.message_capacity *= 2; // Duplicar la capacidad
                char *new_message = malloc(state.message_capacity);
                for (int j = 0; j < state.message_length; j++)
                    new_message[j] = state.message[j];
                new_message[state.message_length] = result;
                new_message[state.message_length + 1] = '\0'; // Asegurarse de que sea una cadena válida
                free(state.message); // Liberar la memoria anterior
                state.message = new_message; // Asignar la nueva cadena
            } else {
                state.message[state.message_length] = result;
                state.message[state.message_length + 1] = '\0'; // Asegurarse de que sea una cadena válida
            }
            state.message_length++;
        }
    }
}

int main(void)
{
    init_server_state(); // Inicializar el estado del servidor

    // Configurar la señal
    struct sigaction sa;
    sa.sa_sigaction = alm_bin;
    sa.sa_flags = SA_SIGINFO; // Usar la estructura siginfo_t
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    // Imprimir el PID del servidor
    ft_putnbr(getpid());
    write(1, "\n", 1);

    // Esperar señales
    while (1)
        pause(); // Usar pause para esperar señales

    return 0;
}