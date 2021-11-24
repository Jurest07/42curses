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

void	ft_putnbr_base(t_llong num, int osn, char *base)
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
