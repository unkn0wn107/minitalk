/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:47:16 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 15:37:34 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_issep(char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset && charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * Removes the specified characters from the begining and end of a string.
 *
 * @param s1 The string to trim.
 * @param set The characters to remove.
 *
 * @returns The trimmed string as a new string.
 * NULL if allocation failed or s1 is NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	strlen;

	if (!s1)
		return (NULL);
	while (*s1 && ft_issep(*s1, set))
		s1++;
	strlen = ft_strlen(s1);
	s1 = s1 + strlen;
	while (strlen != 0 && ft_issep(*(s1 - 1), set) && strlen--)
		s1--;
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	s1 = s1 - strlen;
	ft_strlcpy(str, s1, strlen + 1);
	return (str);
}
