/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:07 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/09 11:07:15 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// void	handler()
// {
// 	// static char	binary_digits = 0;
// 	// static int	bit_recived = 0;
// 	// int			server_pid;
// 	printf("SIGUSR1 received");
// 	printf("SIGUSR2 recived");
// 	// 	if (signum == SIGUSR1)
// 	// 	{
// 	// 		binary_digits = (binary_digits << 1) | 1;
// 	// 	}
// 	// 	else if (signum == SIGUSR2)
// 	// 	{
// 	// 		binary_digits = (binary_digits << 1);
// 	// 	}
// 	// 	bit_recived++;
// 	// 	if (bit_recived == 8)
// 	// 	{
// 	// 		printf("%c", binary_digits);
// 	// 		binary_digits = 0;
// 	// 		bit_recived = 0;
// 	// 	}
// }

void handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("1\n");
    }
    else if (signum == SIGUSR2)
    {
        printf("0\n");
    }
}
int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
	{
		pause();
	}
	return (0);
}
