/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <lis@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:19:18 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 17:45:33 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESSORY_H
# define ACCESSORY_H

# include <stdarg.h>

typedef unsigned long long	t_ullong;
typedef char				t_bool;

# define FALSE 0
# define TRUE 1

# define SPECIAL_FORMAT 1  // #
# define ZERO_PADDED    2  // 0
# define LEFT_ADJUSTED  4  // -
# define SPACE_BEFORE   8  // ' '
# define SIGN_BEFORE    16 // +

# define AVALIABLE_FORMATS "uidxXpcs"
# define AVALIABLE_FLAGS "#0- +"

/*
 * rigwidth - rigorously width (width only meaning part)
 * sftwidth - soft width (width with sign and special symbols as '0x')
 * minwidth - minimal width (given by user)
 */
typedef struct s_place
{
	char	flags;
	int		minwidth;
	int		rigwidth;
	int		sftwidth;
	int		prec;
	char	fmt;

	union u_val
	{
		int				i;
		unsigned int	u;
		char			c;
		char			*s;
		void			*p;
	} v;
}	t_place;

/* utils */
int			min_i(int a, int b);
long long	absll(long long val);
t_bool		addret(int val, int *sum);
int			sumret(int val, int sum);
void		extract_value(t_place *pl, va_list args);

/* parse */
t_bool		parse_place(char const **s, t_place *t);
void		calculate_width_params(t_place *pl);

/* print */
int			print_filler(int fd, t_place const *pl, int stage);
int			print_place(int fd, t_place *pl, va_list args);
int			print_integer(int fd, t_place const *pl);

#endif
