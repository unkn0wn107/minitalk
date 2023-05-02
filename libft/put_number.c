/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 02:16:14 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 02:18:48 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Prints an integer to a file descriptor.
 *
 * @param nb The integer to print.
 * @param fd The file descriptor to print to.
 *
 * @returns size of printed integer or -1 if an error occured
 */
int	ft_putnbr_fd(int nb, int fd)
{
	long int	n;
	int			size;
	int			wsize;

	size = 0;
	n = (long int)nb;
	if (n < 0)
	{
		n *= -1;
		if (ft_putchar_fd('-', fd) == 1)
			size++;
		else
			return (-1);
	}
	if (0 <= n && n < 10)
		return (size + ft_putchar_fd(n + '0', fd));
	else
	{
		wsize = ft_putnbr_fd(n / 10, fd);
		if (wsize > 0 && ft_putchar_fd(n % 10 + '0', fd) == 1)
			size += wsize + 1;
		else
			return (-1);
	}
	return (size);
}

static int	ft_base_error(const char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (1);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[j] == '+')
			return (1);
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_putnbrblen_fd(long int nbr, const char *base, int bselen, int fd)
{
	long long int	nb;
	int				size;
	int				wsize;

	size = 0;
	nb = (long long int)nbr;
	if (nb < 0)
	{
		nb *= -1;
		if (ft_putchar_fd('-', fd) == 1)
			size++;
		else
			return (-1);
	}
	if (0 <= nb && nb < bselen)
		return (size + ft_putchar_fd(base[nb], fd));
	else
	{
		wsize = ft_putnbrblen_fd(nb / bselen, base, bselen, fd);
		if (wsize > 0 && ft_putchar_fd(base[nb % bselen], fd) == 1)
			size += wsize + 1;
		else
			return (-1);
	}
	return (size);
}

int	ft_putnbr_base_fd(long int nbr, const char *base, int fd)
{
	unsigned int	baselen;

	if (ft_base_error(base))
		return (-1);
	baselen = 0;
	while (base[baselen])
		baselen++;
	return (ft_putnbrblen_fd(nbr, base, baselen, fd));
}

int	ft_putunbr_base_fd(unsigned long int nbr, const char *base, int fd)
{
	size_t					baselen;
	int						size;
	int						wsize;

	if (ft_base_error(base))
		return (-1);
	baselen = ft_strlen(base);
	size = 0;
	if (nbr >= baselen)
	{
		wsize = ft_putunbr_base_fd(nbr / baselen, base, fd);
		if (wsize > 0 && ft_putchar_fd(base[nbr % baselen], fd) == 1)
			size += wsize + 1;
		else
			return (-1);
	}
	else if (ft_putchar_fd(base[nbr], fd) == 1)
		return (size + 1);
	else
		return (-1);
	return (size);
}
