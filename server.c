/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:58:53 by omaali            #+#    #+#             */
/*   Updated: 2024/03/19 03:59:21 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t received_signal = 0;
char received_message[1024];

void handle_signal(int signal_number) {
    received_signal = signal_number;
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    printf("Server started. PID: %d\n", getpid());

    while (1) {
        if (received_signal == SIGUSR1) {
            printf("Received message from client: %s\n", received_message);
            received_signal = 0;
        }
    }

    return 0;
}

