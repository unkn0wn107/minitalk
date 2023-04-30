/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:16 by agaley            #+#    #+#             */
/*   Updated: 2023/04/15 19:27:50 by agaley           ###   ########lyon.fr   */
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
	char	bin[9];
	size_t	i;
	size_t	j;

	if (argc != 3 || !argv[2][0])
		return (ft_error(1));
	ft_printf("%d arguments :\n", argc - 1);
	i = 0;
	j = 0;
	while (i < ft_strlen(argv[2]))
	{
		ft_itobarr((unsigned char)argv[2][i], 8, bin);
		while (j < 8)
		{
			if (bin[j] == '0')
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			j++;
			usleep(100);
		}
		usleep(1000);
		// k = 1;
		// while (utf[j][0] == 1)
		// {
		// 	ft_itobarr((unsigned char)argv[2][j + k], 8, bin);
		// 	utf[j++] = ft_btoi(bin);
		// 	j++;
		// }
		i++;
	}
	// ft_printf("%s\n", utf);
	// Encode and send message bits by bits
	// Receive ok from server, exit 0 - if not, exit error 2
	return (0);
}
