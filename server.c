/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:06:21 by agaley            #+#    #+#             */
/*   Updated: 2023/03/11 00:25:36 by agaley           ###   ########lyon.fr   */
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

# include "minitalk.h"

int	main(void)
{

}