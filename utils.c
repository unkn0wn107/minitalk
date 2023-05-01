/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:02:35 by agaley            #+#    #+#             */
/*   Updated: 2023/05/01 22:50:40 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_error(int code)
{
	char	*msg;

	if (code == 1)
		msg = "Erreur d'argument :\n./client (int)PID (char *)message";
	if (code == 2)
		msg = "Erreur sigemptyset ou signaddset";
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
	i = 0;
	while (i < 33)
		buff->byte[i++] = 0;
	return (buff);
}

unsigned char	ft_btouchar(unsigned char *barr)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	c = 0;
	while (barr[i])
	{
		c += (barr[i] - '0') * ft_pow(2, 7 - i);
		i++;
	}
	return (c);
}

unsigned int	ft_btoi32(unsigned char *barr)
{
	size_t			i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (barr[i])
	{
		c += (barr[i] - '0') * ft_pow(2, 31 - i);
		i++;
	}
	return (c);
}
