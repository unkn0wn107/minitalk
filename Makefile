# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/03/11 01:18:08 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRV = server
CLT = client

SRCS = server.c
SRCC = client.c

LIBFT = libft/libft.a
LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft
MAKEFLAGS += --no-print-directory

OBS = server.o
OBC = client.o

CFLAGS = -Wall -Wextra -Werror -O2
CC = gcc

all:	${SRV} ${CLT}

${LIBFT}:
		$(MAKE_LIBFT)

${OBS}:	${SRCS} ${H} ${LIBFT} Makefile 
		${CC} ${CFLAGS} ${SRCS} -c

${SRV}: ${OBS}
		${CC} ${CFLAGS} ${OBS} -o ${SRV} ${LIBFT_FLAGS} 

${OBC}:	${SRCC} ${H} ${LIBFT} Makefile
		${CC} ${CFLAGS} ${SRCC} -c

${CLT}: ${OBC}
		${CC} ${CFLAGS} ${OBC} -o ${CLT} ${LIBFT_FLAGS}

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
