/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:59:31 by omaali            #+#    #+#             */
/*   Updated: 2024/03/19 03:59:45 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    printf("Sending message to server: %s\n", message);
    kill(server_pid, SIGUSR1);

    strcpy(received_message, message);
    kill(server_pid, SIGUSR1);

    return 0;
}

