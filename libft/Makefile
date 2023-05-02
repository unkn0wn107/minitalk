# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:24:11 by agaley            #+#    #+#              #
#    Updated: 2023/04/30 14:19:22 by agaley           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
H = libft.h

SRCS = 	char_checking.c char_conversion.c \
	type_conversion.c \
	number_utils.c buff_utils.c \
	search_compare_str.c search_compare_mem.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c\
	ft_strdup.c ft_calloc.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_strmapi.c ft_striteri.c \
	put_char_str.c put_number.c put_special.c \
	ft_printf.c ft_dprintf.c \
	ft_pow.c \
	stack.c

OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all:	${NAME}

%.o:	%.c ${H} Makefile
		${CC} ${CFLAGS} $< -c

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
		$(foreach obj, ${OBJS}, rm -f ${obj})
		find . -name "*.gch" -delete

fclean:	clean
		find . -name "${NAME}" -delete
		find . -name "a.out" -delete

re:	fclean all
		make

.PHONY:	all clean fclean re
