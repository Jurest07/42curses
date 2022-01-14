/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:27:35 by slight            #+#    #+#             */
/*   Updated: 2022/01/14 19:01:36 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

# define CONVERSIONS "cspdiuxX%"

typedef unsigned int		t_ui;
typedef unsigned long long	t_ull;

int		print_char(char c);
int		print_string(char *s);
int		print_number(int num, int fd);
int		print_hex(t_ui num, char c);
int		ft_putnbr_base(t_ui num, int osn, char *base);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	parse(va_list data, char format, int *sum);
int		digit_count_of_int(int n);
t_ull	jrs_power(int osn, int st);
int		digit_count_of_ui(t_ui n);
int		jrs2_power(int osn, t_ui st);
int		print_unsigned_number(t_ui num);
int		print_pointer(t_ull num, int osn, char *base);
int		ft_printf(const char *format, ...);
int		addret(int num, int *sum);
int		s_len(int n, t_ull m);

#endif
