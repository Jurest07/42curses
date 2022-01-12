/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:44:48 by slight            #+#    #+#             */
/*   Updated: 2022/01/13 00:06:05 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	data;

	va_start(data, format);
	while(*format)
	{
		if (*format == '%')
		{
			++format;
			if (ft_strchr(CONVERSIONS, *format))
				parse(data, *format);
			else 
				return (0);
		}
		else
			write(1, format, 1);
		++format;
	}
	va_end(data, format);
	return (0);
}

int main(void)
{
	char	c1;
	char	*c2;
	int		i;
	unsigned int	hex;
	unsigned int	hex1;

	c1 = 'z';
	c2 = "Andrey";
	i = -12;
	hex = 0xff;
	hex1 = 255;
	ft_printf("hello %c, My name is %s. Im %d years old. OMG \n%d \n%X \n%%", c1, c2, i, hex, hex1);
}
