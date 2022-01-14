/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:44:48 by slight            #+#    #+#             */
/*   Updated: 2022/01/14 19:23:26 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	addret(int num, int *sum)
{
	if (num < 0)
		return (0);
	*sum += num;
	return (1);
}

void	parse(va_list data, char format, int *sum)
{
	if (format == 'c')
		*sum += print_char((char)va_arg(data, int));
	else if (format == 'i' || format == 'd')
		*sum += print_number(va_arg(data, int), 1);
	else if (format == 's')
		*sum += print_string((char *)va_arg(data, char *));
	else if (format == 'u')
		*sum += print_unsigned_number((t_ui)va_arg(data, int));
	else if (ft_strchr("xX", format))
		*sum += print_hex(va_arg(data, t_ui), format);
	else if (format == 'p')
		*sum += print_pointer(va_arg(data, t_ull), 16, "0123456789abcdef");
	else if (format == '%')
		*sum += print_char('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	data;
	int		sum;

	sum = 0;
	va_start(data, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (ft_strchr(CONVERSIONS, *format))
				parse(data, *format, &sum);
			else
				return (-1);
		}
		else if (!addret(write(1, format, 1), &sum))
			return (-1);
		++format;
	}
	va_end(data);
	return (sum);
}
