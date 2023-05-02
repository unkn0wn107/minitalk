/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:06:21 by agaley            #+#    #+#             */
/*   Updated: 2023/05/02 02:20:45 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signum, siginfo_t *info, void *context)
{
	static t_buff	buff;

	(void)context;
	if (!buff.str)
		set_length(&buff, signum);
	if (buff.str)
	{
		receive_byte(buff.byte, signum);
		if (ft_strlen(buff.byte) == 8)
		{
			buff.str[buff.cur] = (unsigned char)ft_btoi(buff.byte);
			clean_byte(buff.byte, 8);
			buff.cur++;
		}
		if (buff.cur == buff.len)
		{
			ft_printf("%s\n", buff.str);
			ft_cleanbuff(&buff);
		}
	}
	kill(info->si_pid, SIGUSR1);
}

static int	receive_signals(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
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
			return (1);
		usleep(10);
	}
}
