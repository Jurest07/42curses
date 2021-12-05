#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

int	jrs1_power(int osn, int st)
{
	if (st == 0)
		return (1);
	return (osn * jrs1_power(osn, st - 1));
}

int	count1_power(int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	int		dell;
	char	temp;

	if (n == 0 || n == -0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	if (n > 0)
		n = -n;
	dell = jrs1_power(10, count1_power(n) - 1);
	while (dell > 0)
	{
		temp = -(n / dell) + 48;
		write(fd, &temp, 1);
		n = n % dell;
		dell = dell / 10;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (c > 256)
		c = c - 256;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
