/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:56 by agaley            #+#    #+#             */
/*   Updated: 2023/03/10 23:58:54 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putunbr_fd(unsigned int nb, int fd)
{
	return (ft_putunbr_base_fd(nb, "0123456789", fd));
}

static int	ft_putlowhex_fd(unsigned int hex, int fd)
{
	return (ft_puthex_fd((unsigned long int)hex, 1, fd));
}

static int	ft_putuphex_fd(unsigned int hex, int fd)
{
	return (ft_puthex_fd((unsigned long int)hex, 0, fd));
}

static int	ft_putflag(char flag, va_list args, int fd)
{
	int	size;

	size = 0;
	if (flag == '%')
		size = ft_putchar_fd('%', fd);
	else if (flag == 'c')
		size = ft_putchar_fd(va_arg(args, int), fd);
	else if (flag == 'd' || flag == 'i')
		size = ft_putnbr_fd(va_arg(args, int), fd);
	else if (flag == 'p')
		size = ft_putptr_fd(va_arg(args, void *), fd);
	else if (flag == 's')
		size = ft_putstr_fd(va_arg(args, char *), fd);
	else if (flag == 'u')
		size = ft_putunbr_fd(va_arg(args, unsigned int), fd);
	else if (flag == 'x')
		size = ft_putlowhex_fd(va_arg(args, unsigned int), fd);
	else if (flag == 'X')
		size = ft_putuphex_fd(va_arg(args, unsigned int), fd);
	return (size);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			size += ft_putflag(format[i], args, fd);
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
