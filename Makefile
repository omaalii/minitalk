# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaali <omaali@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 18:26:42 by omaali            #+#    #+#              #
#    Updated: 2024/03/25 18:26:45 by omaali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

HEADERS = minitalk.h
SRCS = server.c client.c utils.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: server.o utils.o Makefile minitalk.h
	${CC} ${CFLAGS} server.o utils.o -o ${NAME_SERVER}

${NAME_CLIENT}: client.o utils.o Makefile minitalk.h
	${CC} ${CFLAGS} client.o utils.o -o ${NAME_CLIENT}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME_SERVER}
	rm -f ${NAME_CLIENT}

re: fclean all

.PHONY: all clean fclean re
