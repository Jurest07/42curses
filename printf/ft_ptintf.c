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

#include "ft_printf.h"

int	init_format(const char *format, va_list ap)
{
	int f;

	f = 1;
	++format;
	va_start(ap, format);
	if (*format == 'c')
		print_char((char)va_arg(ap, int));
	else if (*format == 's')
		print_string((char*)va_arg(ap, int));
	else if (ft_strchr("xXp", *format))
		print_hex((long)va_arg(ap, int), *format);
	else if (ft_strchr("di", *format))
		print_number((int)va_arg(ap,int));
	else if (*format == 'u')
		return 0;
	else if (*format == '%')
		return 0;
	else
		f = 0;
	return (f);
}

int	ft_ptintf(const char *format, ...)
{
	va_list	ap;
	while(*format)
	{
		if (*format == '%')
			if(init_format(format, ap))
				++format;
		else
			write(1, format, 1);
		++format;
	}
	return (0);
}
