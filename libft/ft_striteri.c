/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:18:25 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 15:27:55 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates over a string and applies a function to each character.
 * Each character is given as a pointer to eventually modify it.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 *
 * @returns None
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned long int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		(*f)(i++, s++);
}
