/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_special.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 02:20:05 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 02:21:06 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long int hex, char low, int fd)
{
	if (low == 1)
		return (ft_putunbr_base_fd(hex, "0123456789abcdef", fd));
	else if (low == 0)
		return (ft_putunbr_base_fd(hex, "0123456789ABCDEF", fd));
	else
		return (-1);
}

/**
 * Writes a pointer address to the file descriptor fd.
 *
 * @param ptr The pointer of which to write the address.
 * @param fd The file descriptor to write to.
 *
 * @returns >0 on success -1 if error occured, cf write return values for others
 */
int	ft_putptr_fd(void *ptr, int fd)
{
	int	size;

	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	size = 0;
	if (ft_putstr_fd("0x", fd) == 2)
		size = 2;
	else
		return (-1);
	size += ft_puthex_fd((unsigned long)ptr, 1, fd);
	if (size < 0)
		return (-1);
	return (size);
}
