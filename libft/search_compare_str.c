/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_compare_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:30:11 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 01:33:52 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of a character in a string.
 *
 * @param s The string to search.
 * @param c The character to search for.
 *
 * @returns The first occurrence of the character (can be '\0') in the string.
 * NULL if the character was not found.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*s2;

	s2 = (char *)s;
	i = 0;
	while (s2[i])
	{
		if (s2[i] == (char)c)
			return (&s2[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return ((void *)0);
}

/**
 * Finds the last occurrence of a character in a string.
 *
 * @param s The string to search.
 * @param c The character to search for.
 *
 * @returns The last occurrence of the character (can be '\0') in the string.
 * NULL if the character was not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s2;

	s2 = (char *)s;
	len = ft_strlen(s2);
	if ((char)c == '\0')
		return ((char *)s + len);
	if (len == 0)
		return ((void *)0);
	while (len--)
		if (s2[len] == (char)c)
			return (&s2[len]);
	return ((void *)0);
}

/**
 * Searches for the first occurrence of the string needle in the string haystack.
 *
 * @param haystack The string to search in.
 * @param needle The substring to search for.
 * @param len The maximum number of characters to search.
 *
 * @returns The first occurrence of the substring needle in the string haystack.
 * A pointer to haystack if needle is empty.
 * NULL if needle is not found or hs is NULL and len 0.
 */
char	*ft_strnstr(const char *hs, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!hs && len == 0)
		return (NULL);
	if (!needle[0])
		return ((char *)hs);
	i = 0;
	while (hs[i])
	{
		j = 0;
		while ((hs[i + j] == needle[j] || needle[j] == '\0') && i + j <= len)
		{
			if (needle[j] == '\0')
				return (&((char *)hs)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/**
 * Compares the first n characters of strings s1 and s2.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The number of characters to compare.
 *
 * @returns The difference between the first characters (as unsigned char)
 * that differ in s1 and s2.
 * 0 if the first n characters are equal or if n is equal to zero.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}
