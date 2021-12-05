#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

typedef unsigned int t_llong;

typedef struct	s_value{
	int				i;
	unsigned int	hex;
	char			c;
	char			*s;

}				t_value;

void	print_char(char c);
void	print_string(char *s);
void	print_number(int num);
void	print_hex(long num, char c);
void	ft_putnbr_base(t_llong num, int osn, char *base);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);

#endif
