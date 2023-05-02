/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:05:44 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 15:20:51 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Duplicates a string and returns a pointer to the duplicate.
 *
 * @param s1 The string to duplicate.
 *
 * @returns A freeable pointer to the duplicated string.
 * NULL if allocation failed.
 */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s1[i])
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return ((char *)0);
	dup[i] = '\0';
	while (i--)
		dup[i] = s1[i];
	return (dup);
}
