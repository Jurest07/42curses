#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef unsigned int t_llong;
void	print_char(char c);
void	print_string(char *s);
void	print_number(int num);
void	print_hex(long num, char c);
void	ft_putnbr_base(t_llong num, int osn, char *base);

#endif
