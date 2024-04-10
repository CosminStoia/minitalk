/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:10 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/10 09:57:17 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_atoi(char *str)
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

static void	ft_sendchar(int server_pid, char *str)
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
			usleep(1000);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 2;
	server_pid = ft_atoi(argv[1]);
	while (i < argc)
	{
		ft_sendchar(server_pid, argv[i]);
		i++;
	}
	return (0);
}
