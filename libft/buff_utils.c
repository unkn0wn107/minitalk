/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:19:36 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:25:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets the first n bytes of the memory pointed to by s to the value of c.
 *
 * @param s The memory area to set.
 * @param c The value to set the memory area to.
 * @param n The number of bytes to set.
 *
 * @returns A pointer to s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n--)
		s2[n] = (unsigned char)c;
	return (s);
}

/**
 * Sets the first n bytes of the memory area pointed to by s to 0 ('\0').
 *
 * @param s The memory area to be zeroed.
 * @param n The number of bytes to be zeroed.
 *
 * @returns None
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/**
 * Copies n bytes from memory areas src to dest (must not overlap).
 *
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 *
 * @returns A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;

	dest2 = (unsigned char *)dest;
	if (!(dest || src))
		return ((void *)0);
	while (n--)
		dest2[n] = ((unsigned char *)src)[n];
	return (dest);
}

/**
 * Copies n bytes from the memory areas src to dest (may overlap).
 *
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 *
 * @returns A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	m;
	void	*tmp;

	if (!(dest || src))
		return (NULL);
	tmp = dest;
	m = n;
	if ((const char *)dest > (const char *)src)
	{
		dest = dest + n - 1;
		src = src + n - 1;
		while (m--)
			*((unsigned char *)(dest--)) = *((unsigned char *)(src--));
	}
	else
	{
		while (m--)
			*((unsigned char *)dest++) = *((unsigned char *)src++);
	}
	return (tmp);
}
