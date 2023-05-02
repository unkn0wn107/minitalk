/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:39:31 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 15:35:17 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_min(size_t val1, size_t val2)
{
	if (val1 <= val2)
		return (val1);
	return (val2);
}

/**
 * Returns a len-long substring of a string, from start index.
 *
 * @param s The string to be sliced.
 * @param start The start index of the substring.
 * @param len The length of the substring.
 *
 * @returns The substring of the string, as a new string.
 * NULL if allocation failed.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	width;

	if (!s)
		return (NULL);
	width = ft_min(ft_strlen(s) - start, len);
	if (start >= ft_strlen(s))
		width = 0;
	str = malloc(sizeof(char) * (width + 1));
	if (!str)
		return (NULL);
	while (*s != '\0' && start--)
		s++;
	i = len;
	j = 0;
	while (*s != '\0' && i--)
	{
		*(str++) = (char)*(s++);
		j++;
	}
	*str = '\0';
	return (str - j);
}
