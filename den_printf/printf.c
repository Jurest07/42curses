/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <lis@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:57:20 by lis               #+#    #+#             */
/*   Updated: 2021/11/09 01:04:57 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "accessory.h"

static int	write_after_percent(int fd, char const **p, va_list args)
{
	int		ret;
	t_place	pl;

	if (!*++*p || (**p == '%' && ++(*p)))
		ret = write(fd, "%", 1);
	else if (parse_place(p, &pl))
		ret = print_place(fd, &pl, args);
	else
		ret = write(fd, "%", 1);
	return (ret);
}

int	ft_vfprintf(int fd, char const *fmt, va_list args)
{
	char const	*p;
	int			sum;

	if (!fmt)
		return (0);
	p = fmt;
	sum = 0;
	while (1)
	{
		while (*p && *p != '%')
			++p;
		if (!addret(write(fd, fmt, p - fmt), &sum))
			return (-1);
		if (!*p)
			return (sum);
		if (!addret(write_after_percent(fd, &p, args), &sum))
			return (-1);
		fmt = p;
	}
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		ret;

	if (!fmt)
		return (0);
	va_start(args, fmt);
	ret = ft_vfprintf(1, fmt, args);
	va_end(args);
	return (ret);
}

int	ft_fprintf(int fd, char const *fmt, ...)
{
	va_list	args;
	int		ret;

	if (!fmt)
		return (0);
	va_start(args, fmt);
	ret = ft_vfprintf(fd, fmt, args);
	va_end(args);
	return (ret);
}
