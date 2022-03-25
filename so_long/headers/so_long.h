/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:09:46 by slight            #+#    #+#             */
/*   Updated: 2022/03/25 21:41:56 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
//# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# define VALIDCHARS "01CEPG\n"
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
	int				die;
	int				count_c;
	int				count_p;
	int				count_e;
	int				keycode;
	unsigned int	count_press;
}				t_gamestatus;

typedef struct s_enemy
{
	t_img	*enemy1;
	t_img	*enemy2;
	t_img	*enemy3;
	t_img	*enemy4;
	t_img	*enemy5;
	t_img	*enemy6;
}				t_enemy;

typedef struct s_game {
	void			*mlx;
	void			*display;
	t_img			*k_right;
	t_img			*k_left;
	t_img			*k_down;
	t_img			*k_up;
	t_img			*floor;
	t_img			*wall;
	t_img			*like;
	t_img			*youtube;
	t_img			*one;
	t_img			*two;
	t_img			*three;
	t_img			*four;
	t_img			*five;
	t_img			*six;
	t_img			*seven;
	t_img			*eight;
	t_img			*nine;
	t_img			*zero;
	t_img			*black;
	t_img			*grave;
	t_coord			exit;
	t_coord			player;
	t_img			*enemy[6];
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
void	draw(t_game *game, int keycode);
int		key_press(int keycode, t_game *game);
int		destroy_hook(int keycode, t_game *game);
void	root_destroy(t_game *game, char *errmsg, int errnum);
char	*ft_inttostr(unsigned int num);
void	texture_load(t_game *game, t_img **img, char *path);
void	draw_c(t_game *game, int i, int j);
void	draw_digit(t_game *game, char move, int i, int j);
void	die_pls(t_game *game);
#endif
