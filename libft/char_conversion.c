/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:18:22 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:18:46 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a character to lowercase.
 *
 * @param c The character to convert.
 *
 * @returns The lowercase version of the character.
 */
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

/**
 * Converts a lowercase character to uppercase.
 *
 * @param c The character to convert.
 *
 * @returns The uppercase version of the character.
 */
int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}
