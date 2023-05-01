/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:06:21 by agaley            #+#    #+#             */
/*   Updated: 2023/05/01 22:54:21 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	clean_byte(unsigned char *byte, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len + 1)
		byte[i++] = 0;
}

static void	receive_byte(unsigned char *byte, int signum)
{
	size_t	l;

	l = ft_ustrlen(byte);
	if (signum == SIGUSR1)
		byte[l] = '0';
	else if (signum == SIGUSR2)
		byte[l] = '1';
}

static void	set_length(t_buff *buff, int signum)
{
	size_t	l;

	l = ft_ustrlen(buff->byte);
	if (l == 32)
	{
		buff->len = ft_btoi32(buff->byte);
		buff->str = (unsigned char *)malloc(sizeof(unsigned char) * buff->len + 1);
		ft_bzero(buff->str, buff->len + 1);
		clean_byte(buff->byte, 32);
		return ;
	}
	receive_byte(buff->byte, signum);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static t_buff	buff;

	(void)context;
	if (!buff.str)
		set_length(&buff, signum);
	if (buff.str)
	{
		receive_byte(buff.byte, signum);
		if (ft_ustrlen(buff.byte) == 8)
		{
			buff.str[ft_ustrlen(buff.str)] = ft_btouchar(buff.byte);
			clean_byte(buff.byte, 8);
		}
		if (ft_ustrlen(buff.str) == buff.len)
		{
			ft_printf("%s\n", buff.str);
			ft_cleanbuff(&buff);
		}
	}
	kill(info->si_pid, SIGUSR1);
}

static int	receive_signals()
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_error(2));
	return (0);
}

int	main(void)
{
	ft_printf("Ready to talk with client, PID = %d\n", getpid());
	while (1)
	{
		if (receive_signals() == 1)
			return (1);
		usleep(1);
	}
}
