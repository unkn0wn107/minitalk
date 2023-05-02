/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:37:25 by agaley            #+#    #+#             */
/*   Updated: 2022/12/17 14:55:05 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory (set to zero) for nmemb elements of size bytes each.
 *
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 *
 * @returns A pointer to the allocated memory.
 * NULL if size is 0 or if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (size && nmemb > SIZE_MAX / size)
		return ((void *)0);
	mem = malloc(nmemb * size);
	if (!mem)
		return ((void *)0);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
