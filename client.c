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

#include "minitalk.h"

static void	send_signal_bits(char character, pid_t pid_server)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if ((character >> bits & 1) == 1)
		{
			if (kill(pid_server, SIGUSR1) == ERROR)
			{
				put_str_fd("Error | Kill Fails", 2);
				break ;
			}
		}
		else
		{
			if (kill(pid_server, SIGUSR2) == ERROR)
			{
				put_str_fd("Error | Kill Fails", 2);
				break ;
			}
		}
		--bits;
		usleep(350);
	}
}

static int	is_valid_arg(char *pid, char *msg)
{
	int	r;
	int	i;

	r = 1;
	i = -1;
	if (msg[0] == '\0')
		r = 0;
	while (r == 1 && pid[++i])
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
			r = 0;
	}
	return (r);
}

int	main(int argc, char **argv)
{
	int	j;

	j = -1;
	if (argc == 3 && is_valid_arg(argv[1], argv[2]))
	{
		while (argv[2][++j])
			send_signal_bits(argv[2][j], ft_atoi(argv[1]));
	}
	else
		put_str_fd("Error | Correct: ./client <PID> Message\n", 2);
	return (0);
}