/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:59:56 by lis               #+#    #+#             */
/*   Updated: 2021/10/16 14:28:29 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	nvx_putnbr_recursive(int n, int fd)
{
	char	digit;

	digit = '0' - (n % 10);
	if (n / 10)
		nvx_putnbr_recursive(n / 10, fd);
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	else
		n = -n;
	nvx_putnbr_recursive(n, fd);
}
