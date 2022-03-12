/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:53:48 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 22:47:58 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm(int sig)
{
	(void)sig;
	write(1, "MESSAGE RECEIVED :)", 19);
	write(1, "\n", 1);
	exit(0);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

int	erro(char *message)
{
	ft_putendl_fd(message, 2);
	return (0);
}

void	send_message(int pid, int c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (!(c & 1 << bit))
		{
			if (kill(pid, SIGUSR1))
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR2))
				exit(0);
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
		return (erro(YELL"\nformat: \n./client pid \"message"YELL"\"\n"));
	pid = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, confirm);
	while (*(*(argv + 2) + i))
		send_message(pid, *(*(argv + 2) + i++));
	send_message(pid, 0);
	while (1)
		pause();
	return (0);
}
