/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:54:19 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:56:40 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a character to the file descriptor fd.
 *
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 *
 * @returns 1 on success -1 if error occured, cf write return values for others
 */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * Prints a string to a file descriptor, followed by a new line ('\n').
 *
 * @param s The string to print.
 * @param fd The file descriptor to print to.
 *
 * @returns None
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/**
 * Prints a string to a file descriptor.
 *
 * @param s The string to print.
 * @param fd The file descriptor to print to.
 *
 * @returns length of printed string or -1 if an error occured
 */
int	ft_putstr_fd(const char *s, int fd)
{
	int	len;

	if (!s)
		return (write(fd, "(null)", 6));
	len = ft_strlen(s);
	return (write(fd, s, len));
}
