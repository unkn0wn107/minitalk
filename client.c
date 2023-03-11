/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:16 by agaley            #+#    #+#             */
/*   Updated: 2023/03/11 01:56:06 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_error(int code)
{
	if (code == 1)
		ft_printf("Erreur d'argument :\n./client (int)PID (char *)message\n");
	if (code == 2)
		ft_printf("Accusé de réception non reçu par le serveur\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3 || !argv[2][0])
		return (ft_error(1));
	ft_printf("%d arguments :\n", argc - 1);
	i = 1;
	while (i < argc)
		ft_printf("%s\n", argv[i++]);
	// Encode and send message bits by bits
	// Receive ok from server, exit 0 - if not, exit error 2
	return (0);
}
