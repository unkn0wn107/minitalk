/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:16 by agaley            #+#    #+#             */
/*   Updated: 2023/03/11 01:14:25 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;

	ft_printf("%d arguments :\n", argc - 1);
	i = 1;
	while (i < argc)
		ft_printf("%s\n", argv[i++]);
	return (0);
}
