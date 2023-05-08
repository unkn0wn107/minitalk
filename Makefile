# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 00:01:07 by agaley            #+#    #+#              #
#    Updated: 2023/05/08 01:15:58 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SRC_SRV = server.c
SRC_CLT = client.c
SRC_UTL = utils.c

LIBFT = libft
LIBFT_FLAGS = -Llibft -lft
MAKE_LIBFT = make -C libft
MAKEFLAGS += --no-print-directory

OBJ_SRV = server.o
OBJ_CLT = client.o
OBJ_UTL = utils.o

CFLAGS = -Wall -Wextra -Werror -pipe
CC = gcc

all:			${NAME}

${NAME}:		${SERVER} ${CLIENT}

${LIBFT}:		FORCE
			$(MAKE_LIBFT)

FORCE: ;

${OBJ_UTL}:		${SRC_UTL} ${H} Makefile
			${CC} ${CFLAGS} ${SRC_UTL} -c

${OBJ_SRV}:		${SRC_SRV} ${H} Makefile
			${CC} ${CFLAGS} ${SRC_SRV} -c

${SERVER}: 	${LIBFT} ${OBJ_UTL} ${OBJ_SRV}
			${CC} ${CFLAGS} ${OBJ_UTL} ${OBJ_SRV} -o $@ ${LIBFT_FLAGS}

${OBJ_CLT}:		${SRC_CLT} ${H} Makefile
			${CC} ${CFLAGS} ${SRC_CLT} -c

${CLIENT}: 	${LIBFT} ${OBJ_UTL} ${OBJ_CLT}
			${CC} ${CFLAGS} ${OBJ_UTL} ${OBJ_CLT} -o $@ ${LIBFT_FLAGS}

clean:
		$(MAKE_LIBFT) $@
		find . -name "${OBJ_SRV}" -delete
		find . -name "${OBJ_CLT}" -delete
		find . -name "${OBJ_UTL}" -delete
		find . -name "*.gch" -delete

fclean:	clean
		$(MAKE_LIBFT) $@
		find . -name "${SERVER}" -delete
		find . -name "${CLIENT}" -delete

re:		fclean all

.PHONY:	all clean fclean re
