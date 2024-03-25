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

#include "minitalk.h"

static void handler(int signal)
{
    static int  bits_count;
    static char c;

    bits_count = 0;
    c = '\0';
    c <<= 1;
    if (signal == SIGUSR1)
        c |= 1;
    bits_count++;
    if (bits_count == 8)
    {
        write(1, &c, 1);
        bits_count = 0;
        c = '\0';
    }
}

static void print_server_pid(void)
{
    pid_t   server_pid;

    server_pid = getpid();
    if (!server_pid)
        put_str_fd("No Server PID", 2);
    else
    {
        put_str_fd("Server PID :", 1);
        put_nbr_fd((int)server_pid, 1);
        write(1, "\n", 1);
    }
}

static void init_sigaction(void)
{
    struct sigaction    sa;

    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    if(sigaction(SIGUSR2, &sa, NULL) == ERROR)
        exit(EXIT_FAILURE);
    if(sigaction(SIGUSR1, &sa, NULL) == ERROR)
        exit(EXIT_FAILURE);
}

int main(void)
{
    print_server_pid();
    init_sigaction();
    while (1)
        pause();
    return (0);

}

