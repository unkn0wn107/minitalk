# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:24:11 by agaley            #+#    #+#              #
#    Updated: 2023/03/11 00:44:43 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRV = server
CLT = client

SRCS = server.c
SRCC = client.c

LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft
MAKEFLAGS += --no-print-directory

OBS = server.o
OBC = client.o

CFLAGS = -Wall -Wextra -Werror -O2
CC = gcc

all:	${SRV} ${CLT}

libft:
		$(MAKE_LIBFT)

${OBS}:	${H} Makefile libft
		${CC} ${CFLAGS} ${LIBFT_FLAGS} ${SRCS} -c

${SRV}: ${OBS}
		${CC} ${CFLAGS} ${OBS} -o ${SRV}

${OBC}:	${H} Makefile libft
		${CC} ${CFLAGS} ${LIBFT_FLAGS} ${SRCS} -c

${CLT}: ${OBC}
		${CC} ${CFLAGS} ${OBC} -o ${CLT}

clean:
		$(MAKE_LIBFT) $@
		find . -name "${OBS}" -delete
		find . -name "${OBC}" -delete
		find . -name "*.gch" -delete

fclean:	clean
		$(MAKE_LIBFT) $@
		find . -name "${SRV}" -delete
		find . -name "${CLT}" -delete

re:		fclean all

.PHONY:	all libft clean fclean re
