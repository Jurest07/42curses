#include "ft_printf.h"
#include <stdio.h>
int	main()
{
	long num = -270882082146;
	char base[17] = "0123456789ABCDEF";
	ft_putnbr_base(num, 16, base);
	printf("\n%X", num);
	return (0);	
}
