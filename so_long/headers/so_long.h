/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:09:46 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:13:58 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define VALIDCHARS "01CEPcep\n"
# define TRUE 1
# define FALSE 0

typedef struct s_iters
{
	int	i;
	int	j;
	int	k;
	int	l;
}				t_iters;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_gamestatus
{
	char			**map;
	int				iter;
	int				count_chars;
	int				height;
	int				width;
	int				count_c;
	int				count_p;
	int				count_e;
	unsigned int	count_press;
}				t_gamestatus;

typedef struct s_game {
	void			*mlx;
	void			*display;
	t_img			*mlx_img;
	t_img			*kuplinov;
	t_img			*floor;
	t_img			*wall;
	t_img			*like;
	t_img			*youtube;
	t_coord			exit;
	t_coord			player;
	t_gamestatus	gamestatus;
}				t_game;

void	die(char *errmes, int errnum);
int		ft_strlen(char *s);
void	putendl_fd(char *mes, int fd);
int		isber(char *map_name);
int		ft_strchr(const char *s, int c);
void	init_gamestatus(t_gamestatus *status);
void	init_iters(t_iters *iters);
void	parse_map(char *file, t_gamestatus *status);
void	fill_map(char *file, t_gamestatus *status);
void	init_game(t_game *game);
void	draw(t_game *game);
int		key_press(int keycode, t_game *game);
int		destroy_hook(int keycode, t_game *game);
void	root_destroy(t_game *game, char *errmsg, int errnum);
void	ft_putnbr(unsigned int num);
#endif
