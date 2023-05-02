/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_compare_mem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:35:25 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:36:07 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of a byte within n bytes of a memory area.
 *
 * @param s The memory area to search into.
 * @param c The byte to search for.
 * @param n The number of bytes to search.
 *
 * @returns A pointer to the first occurrence of c in s, or NULL if c is not
 * found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	s--;
	while (n-- && s++)
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
	return ((void *)0);
}

/**
 * Compares the first n bytes (as unsigned char) of memory areas s1 and s2.
 *
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of characters to compare.
 *
 * @returns The difference between the first bytes (as unsigned char)
 * that differ in s1 and s2.
 * 0 if the first n bytes are equal or if n is equal to zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	diff;

	while (n--)
	{
		diff = (*(unsigned char *)s1++) - (*(unsigned char *)s2++);
		if (diff != 0)
			return (diff);
	}
	return (0);
}
