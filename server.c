/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:06:21 by agaley            #+#    #+#             */
/*   Updated: 2023/05/04 00:41:32 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum, siginfo_t *info, void *context)
{
	static t_buff	buff;

	(void)context;
	if (!buff.str && buff.len == 0)
		set_length(&buff, signum);
	if (!buff.str && buff.len > 0)
	{
		kill(info->si_pid, SIGUSR2);
		exit(ft_error(3));
	}
	if (buff.str)
	{
		receive_byte(buff.byte, signum);
		if (ft_strlen(buff.byte) == 8)
		{
			buff.str[buff.cur] = (unsigned char)ft_btoi(buff.byte);
			clean_byte(buff.byte, 8);
			buff.cur++;
		}
		if (buff.cur == buff.len && ft_printf("%s\n", buff.str))
			ft_cleanbuff(&buff);
	}
	kill(info->si_pid, SIGUSR1);
}

static int	receive_signals(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigemptyset(&sa.sa_mask) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR1) == -1
		|| sigaddset(&sa.sa_mask, SIGUSR2) == -1
		|| sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_error(2));
	return (0);
}

int	main(void)
{
	ft_printf("Ready to print from clients, PID = %d\n", getpid());
	while (1)
	{
		if (receive_signals() == 1)
			exit(1);
		usleep(10);
	}
}
