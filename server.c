/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:06:21 by agaley            #+#    #+#             */
/*   Updated: 2023/04/15 19:54:50 by agaley           ###   ########lyon.fr   */
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
#include <time.h>

static void	print_msg(unsigned char *utfbin)
{
	size_t			len;
	size_t			i;
	size_t			j;
	unsigned char	utf[5];
	unsigned char	bin8[9];

	len = ft_ustrlen(utfbin);
	ft_printf("len - %d\n", len);
	i = 0;
	while (i < 4)
	{
		if (8 * i > len)
			i = 4;
		else
		{
			j = 0;
			while (j < 8)
			{
				bin8[j] = utfbin[8 * i + j];
				j++;
			}
			ft_printf("utfbin - %s\n", bin8);
			utf[i++] = ft_btoi(bin8);
		}
	}
	printf("utf - %s\n", utf);
}

static void	handler(int signum)
{
	static unsigned char	utfbin[33];
	size_t			l;
	size_t			i;

     clock_t start, end;
     double time_taken;

	l = ft_ustrlen(utfbin);
	if (l == 32 || ((l == 8 || l == 16 || l == 24) && signum == SIGUSR1))
	{
		start = clock();
		print_msg(utfbin);
		end = clock();
     	time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("fun() took %f seconds to execute \n", time_taken);
		i = 0;
		while (i < 33)
		{
			utfbin[i] = 0;
			i++;
		}
	}
	l = ft_ustrlen(utfbin);
	if (signum == SIGUSR1)
		utfbin[l] = '0';
	else if (signum == SIGUSR2)
		utfbin[l] = '1';
}

static void	receive_signals()
{
	struct sigaction sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO; /* Restart functions if interrupted by handler */
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Sigaction configuration error");
}

int	main(void)
{
	ft_printf("Ready to talk with client, PID = %d\n", getpid());
	while (1)
	{
		//pause(); // wait for signal to reach server
		receive_signals();
		usleep(1);
		// print_msg();
		// notify_client();
	}
}
