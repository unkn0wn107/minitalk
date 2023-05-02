/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:55:40 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 15:30:31 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **tab, size_t wn)
{
	while (wn--)
		free(tab[wn]);
	free(tab);
	return (NULL);
}

static size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static char	*ft_strdup_word(char const *str, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	if (i == 0)
		word[i] = '\0';
	else
		ft_strlcpy(word, str, i + 1);
	return (word);
}

static size_t	ft_move_count(char const *str, char c, int eq)
{
	size_t	i;

	i = 0;
	while (str[i] && eq == 1 && str[i] == c)
		i++;
	while (str[i] && eq == 0 && str[i] != c)
		i++;
	return (i);
}

/**
 * Splits a string into a NUL-terminated array of words (delimited by c).
 *
 * @param str The string to split.
 * @param c The delimiting character.
 *
 * @returns A NUL-terminated array of words.
 */
char	**ft_split(char const *str, char c)
{
	char const	*save;
	size_t		wn;
	char		**tab;

	tab = (char **)malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (!tab || !str)
		return (NULL);
	save = str;
	wn = 0;
	while (*str)
	{
		str = str + ft_move_count(str, c, 1);
		tab[wn] = ft_strdup_word(str, c);
		if (!tab[wn])
			return (ft_freeall(tab, wn));
		if (*str && *str != c)
			wn++;
		str = str + ft_move_count(str, c, 0);
		str = str + ft_move_count(str, c, 1);
	}
	if (wn == 0 && tab[0] && *save)
		free(tab[0]);
	tab[wn] = NULL;
	return (tab);
}
