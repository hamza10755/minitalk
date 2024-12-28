/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:57:35 by hbelaih           #+#    #+#             */
/*   Updated: 2024/12/02 09:33:20 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_atoi(const char *n)
{
	int	sign;
	int	c;
	int	i;

	sign = 1;
	c = 0;
	i = 0;
	while (ft_isspace(n[i]))
	{
		i++;
	}
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		c = c * 10 + (n[i] - '0');
		i++;
	}
	return (c * sign);
}

void	atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	int		i;

	if (ac != 3)
	{
		ft_printf("Error\n");
		exit(0);
	}
	pid = ft_atoi(av[1]);
	msg = av[2];
	i = 0;
	while (msg[i])
	{
		atob(pid, msg[i]);
		i++;
	}
}
