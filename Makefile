# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/04/30 22:06:32 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRV = server
CLT = client

SRCS = server.c
SRCC = client.c
UTIL = utils.c

LIBFT = libft/libft.a
LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft
MAKEFLAGS += --no-print-directory

OBS = server.o
OBC = client.o
OBU = utils.o

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CC = gcc

all:	${SRV} ${CLT}

${LIBFT}:
		$(MAKE_LIBFT)

${OBU}:	${UTIL} ${H} ${LIBFT} Makefile
		${CC} ${CFLAGS} ${UTIL} -c

${OBS}:	${SRCS} ${H} ${LIBFT} Makefile
		${CC} ${CFLAGS} ${SRCS} -c

${SRV}: ${OBU} ${OBS}
		${CC} ${CFLAGS} ${OBU} ${OBS} -o ${SRV} ${LIBFT_FLAGS}

${OBC}:	${SRCC} ${H} ${LIBFT} Makefile
		${CC} ${CFLAGS} ${SRCC} -c

${CLT}: ${OBU} ${OBC}
		${CC} ${CFLAGS} ${OBU} ${OBC} -o ${CLT} ${LIBFT_FLAGS}

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
