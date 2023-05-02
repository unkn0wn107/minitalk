/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:12:03 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:13:16 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a character is alphanumeric.
 *
 * @param c The character to check.
 *
 * @returns 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/**
 * Checks if a character is an alphabetic character.
 *
 * @param c The character to check.
 *
 * @returns 1 if the character is alphabetical, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * Checks if a character is ASCII.
 *
 * @param c The character to check.
 *
 * @returns 1 if the character is ASCII, 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

/**
 * Checks if a character is a digit (0-9).
 *
 * @param c The character to check.
 * @returns 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/**
 * Checks if a character is printable including space.
 *
 * @param c The character to check.
 *
 * @returns 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
