/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:25:49 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 15:26:13 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Joins two strings together.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 *
 * @returns A new string with joined s1 and s2.
 * NULL if allocation failed.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	out = str;
	while (len1--)
		*(str++) = (char)*(s1++);
	while (len2--)
		*(str++) = (char)*(s2++);
	*str = '\0';
	return (out);
}
