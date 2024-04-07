/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:10 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/07 19:12:35 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	ft_sendbit(int server_pid, char *str)
{
	int	j;
	int	i;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			bit = (str[i] >> j) & 1;
			if (bit == 1)
				kill(server_pid, SIGUSR1);
			else if (bit == 0)
				kill(server_pid, SIGUSR2);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
		return (0);
	server_pid = ft_atoi(argv[1]);
	if(server_pid <= 0)
	{
		printf("Invalid server PID\n");
	}
	ft_sendbit(server_pid, argv[2]);
	return (0);
}
