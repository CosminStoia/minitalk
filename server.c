/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:32:07 by cstoia            #+#    #+#             */
/*   Updated: 2024/04/10 09:57:18 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	handler(int signum)
{
	static unsigned char	binary_digits = 0;
	static int				bit_recived = 0;

	if (signum == SIGUSR1)
		binary_digits = (binary_digits << 1) | 1;
	else if (signum == SIGUSR2)
		binary_digits = (binary_digits << 1);
	bit_recived++;
	if (bit_recived == 8)
	{
		write(1, &binary_digits, 1);
		binary_digits = 0;
		bit_recived = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
