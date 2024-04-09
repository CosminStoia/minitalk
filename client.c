/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:10 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/09 11:27:54 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
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

// void	ft_sendbit(int server_pid, char c)
// {
// 	int	i;
// 	static int	bit;

// 	i = 7;
// 	while (i >= 0)
// 	{
// 		bit = (c >> i) & 1;
// 		if (bit == 1)
// 		{
// 			kill(server_pid, SIGUSR1);
// 			printf("1");
// 		}
// 		else if (bit == 0)
// 		{
// 			kill(server_pid, SIGUSR2);
// 			printf("0");
// 		}
// 		i--;
// 		usleep(50000);
// 	}
// }

// void	ft_sendchar(int server_pid, char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		ft_sendbit(server_pid, str[i]);
// 		i++;
// 	}
// 	ft_sendbit(server_pid, '\0');
// }

void	ft_sendchar(int server_pid, char *str)
{
	int		i;
	char	c;
	int		bit;

	while (*str != '\0')
	{
		c = *str++;
		i = 7;
		while (i >= 0)
		{
			bit = (c >> i) & 1;
			if (bit == 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(50000);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (printf("Incorrect number of arguments\n"));
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || (kill(server_pid, 0) == -1))
	{
		printf("Invalid server PID\n");
	}
	ft_sendchar(server_pid, argv[2]);
	return (0);
}
