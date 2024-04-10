/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:07 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/09 19:02:43 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int signum)
{
	static char	binary_digits = 0;
	static int	bit_recived = 0;

	if (signum == SIGUSR1)
		binary_digits = (binary_digits << 1) | 1;
	else if (signum == SIGUSR2)
		binary_digits = (binary_digits << 1);
	bit_recived++;
	printf("bit_rec: %d", bit_recived);
	if (bit_recived == 8)
	{
		printf("%d", binary_digits);
		printf("%c", binary_digits);
		binary_digits = 0;
		bit_recived = 0;
	}
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
