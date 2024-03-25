/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:01:58 by omaali            #+#    #+#             */
/*   Updated: 2024/03/23 21:02:01 by omaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "minitalk.h"

# define ERROR -1

void	put_str_fd(char *str, int fd);
int		ft_atoi(const char *str);
void	put_nbr_fd(int nb, int fd);

#endif