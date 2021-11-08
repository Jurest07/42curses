/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:44:48 by slight            #+#    #+#             */
/*   Updated: 2021/11/08 14:44:25 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	init_format(const char *format)
{
	++format;
	if (*format == 'c')
		return ;
	if (*format == 's')
		return ;
	if (*format == 'p')
		return ;
	if (*format == 'd')
		return ;
	if (*format == 'i')
		return ;
	if (*format == 'u')
		return ;
	if (*format == 'x')
		return ;
	if (*format == 'X')
		return ;
	if (*format == '%')
		return ;
}

int	ft_ptintf(const char *format, ...)
{
	va_list	ap;
	va_start (ap, format);
	while(*format)
	{
		if (*format == '%')
			init_format(format, ap);
	}
}
