#include "ft_printf.h"
#include <stdio.h>
int	s_len(int osn, t_llong num)
{
	int dell;

	if (num == 0)
		return (1);
	dell = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		num /= osn;
		++dell;
	}
	return (dell);
}

char	*alocate_string(int *dell, t_llong num)
{
	char *s;

	if (num < 0)
	{
		s = malloc(sizeof(char) * (*dell + 2));
		*dell = *dell + 1;
	}
		else
		s = malloc(sizeof(char) * (*dell + 1));
	return (s);
}

int	ft_putnbr_base(t_llong num, int osn, char *base)
{
	int dell;
	char *s;
	int i;
	int f;

	dell = s_len(osn, num);
	f = dell;
	s = malloc(sizeof(char) * (dell + 2));
	i = 0;
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	while (i < f)
	{
		s[dell - i - 1] = base[num % osn];
		++i;
		num /= osn;
	}
	s[dell] = '\0';
	i = print_string(s);
	free(s);
	return (i);	
}

int	ft_putunsnbr(unsigned int num)
{
	int		dell;
	char	temp;
	int		sum;

	sum = 0;
	if (num == 0)
		return (write(1, "0", 1));
	dell = jrs2_power(10, count2_power(num) - 1);
	while (dell > 0)
	{
		temp = num / dell + 48;
		if(!addret(write(1, &temp, 1), &sum))
			return (-1);
		num = num % dell;
		dell = dell / 10;
	}
	return (sum);
}

int	print_pointer(unsigned long num, int osn, char *base)
{
	int dell;
	char *s;
	int i;
	int f;

	dell = s_len(osn, num);
	f = dell;
	s = alocate_string(&dell, num);
	i = 0;
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	while (i < f)
	{
		s[dell - i - 1] = base[num % osn];
		++i;
		num /= osn;
	}
	s[dell] = '\0';
	print_string(s);
	free(s);	
}
