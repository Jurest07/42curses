#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

# define CONVERSIONS "cspdiuxX%"

typedef unsigned int t_llong;

typedef struct	s_value{
	int				i;
	unsigned int	hex;
	char			c;
	char			*s;

}				t_value;

int		print_char(char c);
int		print_string(char *s);
int		print_number(int num);
int		print_hex(long num, char c);
int		ft_putnbr_base(t_llong num, int osn, char *base);
size_t	ft_strlen(const char *s);
int		ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);
int		parse(va_list data, char format);
int		count1_power(int n);
int		jrs1_power(int osn, int st);
int		count2_power(unsigned int n);
int		jrs2_power(int osn, unsigned int st);
int		ft_putunsnbr(unsigned int num);
int		print_unsigned_number(unsigned int num);
int		print_pointer(unsigned long num, int osn, char *base);
int		ft_printf(const char *format, ...);
int		addret(int num, int* sum);
#endif
