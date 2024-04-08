/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:07 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/08 14:39:36 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

char	binary_to_char(char *binary_code)
{
	int		i;
	int		decimal_value;
	char	character;

	i = 0;
	decimal_value = 0;
	while (binary_code[i] != '\0')
	{
		decimal_value = decimal_value * 2 + (binary_code[i] - '0');
		i++;
	}
	character = (char)decimal_value;
	return (character);
}

void	handler(int signum)
{
	static char	binary_digits = 0;
	static int	bit_recived = 0;

	if (signum == SIGUSR1)
	{
		binary_digits = (binary_digits << 1) | 1;
		printf("%c", binary_digits);
	}
	else if (signum == SIGUSR2)
	{
		binary_digits = (binary_digits << 1);
		printf("%c", binary_digits);
	}
	bit_recived++;
	if (bit_recived == 8)
	{
		printf("%c", binary_to_char(&binary_digits));
		binary_digits = 0;
		bit_recived = 0;
	}
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
