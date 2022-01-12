#include "ft_printf.h"
#include <stdio.h>
int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	return (write(1, s, ft_strlen(s)));	
}

int	print_number(int num)
{
	return (ft_putnbr_fd(num, 1));
}

int	print_hex(long num, char c)
{
	if (c == 'X')
		return (ft_putnbr_base(num, 16, "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_putnbr_base(num, 16, "0123456789abcdef"));
}

int	print_unsigned_number(unsigned int num)
{
	return (ft_putunsnbr(num));
}
