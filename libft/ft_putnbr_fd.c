/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:49:08 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 16:03:17 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	jrs1_power(int osn, int st)
{
	if (st == 0)
		return (1);
	return (osn * jrs1_power(osn, st - 1));
}

int	count1_power(int n)
{
	int	p;

	p = 0;
	while (n != 0)
	{
		n = n / 10;
		++p;
	}
	return (p);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		dell;
	char	temp;

	if (n == 0 || n == -0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	if (n > 0)
		n = -n;
	dell = jrs1_power(10, count1_power(n) - 1);
	while (dell > 0)
	{
		temp = -(n / dell) + 48;
		write(fd, &temp, 1);
		n = n % dell;
		dell = dell / 10;
	}
}
