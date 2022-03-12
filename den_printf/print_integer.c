/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:41:54 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 01:42:31 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "accessory.h"
#include "libft/libft.h"

/*
 * fmt may be i, d, u, x or X
 */
static int	print_integer_(int fd, t_ullong val, int base, char *digits)
{
	char	digit;
	int		sum;

	digit = digits[(val % base)];
	sum = 0;
	if (
		val / base
		&& !addret(print_integer_(fd, val / base, base, digits), &sum)
	)
		return (-1);
	if (!addret(write(fd, &digit, 1), &sum))
		return (-1);
	return (sum);
}

int	print_integer(int fd, t_place const *pl)
{
	if (pl->fmt == 'p')
		return (print_integer_(fd, (t_ullong)pl->v.p, 16, "0123456789abcdef"));
	if (pl->fmt == 'u')
		return (print_integer_(fd, pl->v.u, 10, "0123456789"));
	if (pl->fmt == 'i' || pl->fmt == 'd')
		return (print_integer_(fd, absll(pl->v.i), 10, "0123456789"));
	if (pl->fmt == 'x')
		return (print_integer_(fd, pl->v.u, 16, "0123456789abcdef"));
	if (pl->fmt == 'X')
		return (print_integer_(fd, pl->v.u, 16, "0123456789ABCDEF"));
	return (-1);
}
