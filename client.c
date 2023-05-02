/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:16 by agaley            #+#    #+#             */
/*   Updated: 2023/05/02 02:31:32 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	transmit_byte(unsigned int byte, pid_t pid,
	const sigset_t *restrict set, int *restrict sig)
{
	char		bin[9];
	size_t		i;

	i = 0;
	ft_itob(byte, 8, bin);
	while (i < 8)
	{
		if (bin[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sigwait(set, sig);
		i++;
	}
}

static void	transmit_len(unsigned int byte, pid_t pid,
	const sigset_t *restrict set, int *restrict sig)
{
	char		bin[33];
	size_t		i;

	i = 0;
	ft_itob(byte, 32, bin);
	while (i < 32)
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
	if (sigemptyset(&set) == -1 || sigaddset(&set, SIGUSR1) == -1
		|| sigprocmask(SIG_BLOCK, &set, NULL) == -1)
		return (ft_error(2));
	i = 0;
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	transmit_len(len, pid, &set, &sig);
	while (i < len)
		transmit_byte((unsigned char)argv[2][i++], pid, &set, &sig);
	return (0);
}
