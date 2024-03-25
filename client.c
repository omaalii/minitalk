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

static void	send_bits(char c, pid_t pid_server)
{
	int	bits;

	bits = 7;
	while(bits >= 0)
	{
		if ((c >> bits & 1) == 1)
		{
			//kill(pid_server, SIGUSR1);
			if (kill(pid_server, SIGUSR1) == -1)
			{	
				put_str_fd("Error | Kill Failed", 2);
				break ;
			}
		}
		else
		{
			if(kill(pid_server, SIGUSR2 == ERROR))
			{
				put_str_fd("Error | Kill failed", 2);
				break ;
			}
		}
	}
	--bits;
	usleep(200);
}

static int	valid_arg(char *msg, char *pid)
{
	int	t;
	int	i;

	t = 1;
	i = -1;
	if (msg[0] == '\0')
		t = 0;
	while (t == 1 && pid[i++])
	{
		if (!(pid[i] >= '0' && pid[i] <= '9'))
			t = 0;
	}
	return (t);
}

int	main(int argc, char **argv)
{
	int	j;

	j = -1;
	if (argc == 3 && valid_arg(argv[1], argv[2]) && ft_atoi(argv[1]) != -1)
	{
		while (argv[2][j++])
			send_bits(argv[2][j], ft_atoi(argv[1]));
	}
	else
		put_str_fd("Error,| Correct: ./client <PID> Message\n", 2);
    return 0;
}