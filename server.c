/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:06:21 by agaley            #+#    #+#             */
/*   Updated: 2023/05/01 21:42:37 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// You can have one global variable per program (one for the client and one for
// the server), but you will have to justify their use.

// You must create a communication program in the form of a client and a server.
// • The server must be started first. After its launch, it has to print its PID.
// • The client takes two parameters:
// ◦ The server PID.
// ◦ The string to send.
// • The client must send the string passed as a parameter to the server.
// Once the string has been received, the server must print it.
// • The server has to display the string pretty quickly. Quickly means that if you think
// it takes too long, then it is probably too long.
// • Your server should be able to receive strings from several clients in a row without
// needing to restart.
// • The communication between your client and your server has to be done only using
// UNIX signals.
// • You can only use these two signals: SIGUSR1 and SIGUSR2.

// BONUS
// • The server acknowledges every message received by sending back a signal to the
// client.
// • Unicode characters support!

#include "minitalk.h"

static void	clean_byte(unsigned char *byte, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
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
		ft_printf("len: %s\n", buff->byte);
		buff->len = ft_btoi32(buff->byte);
		ft_printf("len: %d\n", buff->len);
		buff->str = (unsigned char *)malloc(sizeof(unsigned char) * buff->len + 1);
		ft_bzero(buff->str, buff->len + 1);
		clean_byte(buff->byte, 33);
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
			clean_byte(buff.byte, 9);
		}
		// ft_printf("msglen: %d\n", msglen);
		if (ft_ustrlen(buff.str) == buff.len)
		{
			ft_printf("%s\n", buff.str);
			ft_cleanbuff(&buff);
		}
	}
	kill(info->si_pid, SIGUSR1);
	// ft_printf("Pong to %d\n", info->si_pid);
}

static void	receive_signals()
{
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	// sigemptyset(&sa.sa_mask);
	// sigaddset(&sa.sa_mask, SIGUSR1);
	// sigaddset(&sa.sa_mask, SIGUSR2);
	sigfillset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Sigaction configuration error");
}

int	main(void)
{
	ft_printf("Ready to talk with client, PID = %d\n", getpid());
	while (1)
	{
		receive_signals();
		usleep(1);
	}
}
