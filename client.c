/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:16 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 21:29:14 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_error(int code)
{
	char	*msg;

	if (code == 1)
		msg = "Erreur d'argument :\n./client (int)PID (char *)message";
	if (code == 2)
		msg = "Erreur sigemptyset ou signaddset";
	if (code == 3)
		msg = "Accusé de réception non reçu par le serveur";
	ft_printf("%s\n", msg);
	return (1);
}

void	transmit_byte(unsigned int byte, unsigned int bits, pid_t pid, const sigset_t *restrict set, int *restrict sig)
{
	char		bin[bits + 1];
	size_t		i;

	i = 0;
	ft_itobarr(byte, bits + 1, bin);
	ft_printf("%s\n", bin);
	while (i < bits + 1)
	{
		if (bin[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sigwait(set, sig);
		i++;
	}
}

int	main(int argc, char **argv)
{
	sigset_t	set;
	int			sig;
	int			pid;
	size_t		i;
	size_t		len;

	if (argc != 3 || !argv[2][0])
		return (ft_error(1));
	if (sigemptyset(&set) == -1 || sigaddset(&set, SIGUSR1) == -1 || sigprocmask(SIG_BLOCK, &set, NULL) == -1)
		return (ft_error(2));
	i = 0;
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	transmit_byte(len, 32, pid, &set, &sig);
	while (i < len)
		transmit_byte(argv[2][i++], 8, pid, &set, &sig);
	return (0);
}
