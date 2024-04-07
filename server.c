/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:07 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/05 19:16:03 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Signal recived from SIGUSR1: %d\n", signum);
	else if (signum == SIGUSR2)
		printf("Signal recived from SIGUSR2: %d\n", signum);
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	if (signal(SIGUSR1, handler) == SIG_ERR)
	{
		printf("Failed to set up a signal handler");
		return (1);
	}
	if (signal(SIGUSR2, handler) == SIG_ERR)
	{
		printf("Failed to set up a signal handler");
		return (1);
	}
	while (1)
		sleep(1);
	return (0);
}
