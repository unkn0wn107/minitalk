/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:02:35 by agaley            #+#    #+#             */
/*   Updated: 2023/05/04 00:12:20 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_error(int code)
{
	char	*msg;

	if (code == 1)
		msg = "Arg error :\n./client (int)PID (char *)message";
	if (code == 2)
		msg = "Signal initialization error";
	if (code == 3)
		msg = "Memory allocation error";
	ft_printf("%s\n", msg);
	return (1);
}

/**
 * Reinitialize and clean the buffer
 *
 * @param buff The buffer to clean up.
 **/
t_buff	*ft_cleanbuff(t_buff *buff)
{
	ssize_t	i;

	if (buff->str)
		free(buff->str);
	buff->str = NULL;
	buff->len = 0;
	buff->cur = 0;
	i = 0;
	while (i < 33)
		buff->byte[i++] = 0;
	return (buff);
}

void	clean_byte(char *byte, size_t bits)
{
	size_t	i;

	i = 0;
	while (i < bits + 1)
		byte[i++] = 0;
}

void	receive_byte(char *byte, int signum)
{
	size_t	l;

	l = ft_strlen(byte);
	if (signum == SIGUSR1)
		byte[l] = '0';
	else if (signum == SIGUSR2)
		byte[l] = '1';
}

void	set_length(t_buff *buff, int signum)
{
	size_t	l;

	l = ft_strlen(buff->byte);
	if (l == 32)
	{
		buff->len = ft_btoi(buff->byte);
		buff->str = malloc(sizeof(unsigned char) * buff->len + 1);
		clean_byte(buff->byte, 32);
		return ;
	}
	receive_byte(buff->byte, signum);
}
