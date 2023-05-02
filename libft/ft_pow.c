/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:12:32 by agaley            #+#    #+#             */
/*   Updated: 2023/03/22 00:56:16 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
* Raise a number to a power.
*
* @param nb - number to raise to power
* @param power - power to raise the number to
*
* @return the number raised to the power
*/
int	ft_pow(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		res = 0;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
