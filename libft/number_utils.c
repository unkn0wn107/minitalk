/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:47:02 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:47:12 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int nbr)
{
	int			i;
	int			min;
	long int	n;

	i = 0;
	min = 0;
	n = nbr;
	if (n < 0)
	{
		n *= -1;
		min = 1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (++i + min);
}

void	ft_nbrcpy(char *str, int nbr)
{
	long int	n;

	n = nbr;
	if (n < 0)
		n *= -1;
	str = str + ft_nbrlen(nbr);
	*(str--) = '\0';
	if (n == 0)
		*(str--) = '0';
	while (n != 0)
	{
		if (n < 10)
			*(str--) = n + '0';
		else
			*(str--) = n % 10 + '0';
		n /= 10;
	}
	if (nbr < 0)
		*str = '-';
}
