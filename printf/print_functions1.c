#include "ft_printf.h"
#include <stdio.h>
void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_string(char *s)
{
	write(1, s, ft_strlen(s));	
}

void	print_number(int num)
{
	ft_putnbr_fd(num, 1);
}

void	print_hex(long num, char c)
{
	if (c == 'X')
		ft_putnbr_base(num, 16, "0123456789ABCDEF");
	else if (c == 'x')
		ft_putnbr_base(num, 16, "0123456789abcdef");
	else
		ft_putnbr_base(num, 10, "0123456789");
}

void	print_unsigned_number(unsigned int num)
{
	ft_putunsnbr(num);
}
