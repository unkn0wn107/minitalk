/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:02:35 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 22:02:40 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * Get the buffer corresponding to the pid in an array of buffers.
 * If not found, create a new buffer for this pid.
 *
 * @param buff The buffers array to seek.
 * @param pid The pid of the buffer to seek.
 *
 * @returns t_buff buffer corresponding to the pid, or NULL upon error
 **/
t_buff	*ft_getbuff(t_stack *stack, int pid)
{
	t_node	*node;
	t_buff	*buff;

	node = stack->head;
	while (node->next)
	{
		buff = node->addr;
		if (buff->pid == pid)
			return (buff);
		node = stack->head;
	}
	buff = node->addr;
	if (buff->pid == pid)
		return (buff);
	buff = malloc_n_collect(stack, sizeof(t_buff));
	if (!buff)
		return (NULL);
	buff->pid = pid;
	return (buff);
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
	buff->pid = 0;
	i = 0;
	while (i < 33)
		buff->byte[i++] = '\0';
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
