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
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'c')
				print_char((char) va_arg(ap, int));
			if (*format == 'i')
				print_number(va_arg(ap, int));
			if(ft_strchr("xX", *format))
				print_hex(va_arg(ap, long), *format);
		}
		else
			write(1, format, 1);
		++format;
	}
	return (0);
}

int main(void)
{
	char	c1;
	char	*c2;
	int		i;
	unsigned int	hex;

	c1 = 'a';
	c2 = "And";
	i = 21;
	hex = 0x782abc;
	ft_printf("hello %c, My name is . Im %i years old. OMG \n%x \n%X \n", c1, i, hex, hex);
}
