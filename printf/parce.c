#include <stdio.h>
#include "ft_printf.h"

void	parse(va_list data, char format)
{
	if (format == 'c')
		print_char((char)va_arg(data, int));
	else if (format == 'i')
		print_number(va_arg(data, int));
	else if (format == 's')
		print_string((char*)va_arg(data, char*));
	else if (format == 'u')
		print_unsigned_number((unsigned int)va_arg(data, int));
	else if (ft_strchr("xX", format))
		print_hex(va_arg(data, long), format);
	else if (format == 'd')
		print_number(va_arg(data, int));
	else if (format == 'p')
		print_pointer(va_arg(data, unsigned long), 16, "0123456789abcdef");
	else if (format == '%')
		print_char('%');
}

int	jrs2_power(int osn, unsigned int st)
{
	if (st == 0)
		return (1);
	return (osn * jrs1_power(osn, st - 1));
}

int	count2_power(unsigned int n)
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

int	addret(int num, int* sum)
{
	if (num < 0)
		return (0);
	*sum += num;
	return (1);
}
