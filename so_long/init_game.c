/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:00:11 by slight            #+#    #+#             */
/*   Updated: 2022/03/24 00:03:46 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	texture_load(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

static void	texture_init2(t_game *game)
{
	texture_load(game, &game->enemy[0], "./assets/enemy1.xpm");
	texture_load(game, &game->enemy[1], "./assets/enemy2.xpm");
	texture_load(game, &game->enemy[2], "./assets/enemy3.xpm");
	texture_load(game, &game->enemy[3], "./assets/enemy4.xpm");
	texture_load(game, &game->enemy[4], "./assets/enemy5.xpm");
	texture_load(game, &game->enemy[5], "./assets/enemy6.xpm");
}

static void	texture_init(t_game *game)
{
	texture_load(game, &game->k_right, "./assets/kuplinov_right.xpm");
	texture_load(game, &game->k_left, "./assets/kuplinov_left.xpm");
	texture_load(game, &game->k_down, "./assets/kuplinov_down.xpm");
	texture_load(game, &game->k_up, "./assets/kuplinov_up.xpm");
	texture_load(game, &game->like, "./assets/like.xpm");
	texture_load(game, &game->youtube, "./assets/youtube.xpm");
	texture_load(game, &game->wall, "./assets/wall.xpm");
	texture_load(game, &game->floor, "./assets/floor.xpm");
	texture_load(game, &game->one, "./assets/1.xpm");
	texture_load(game, &game->two, "./assets/2.xpm");
	texture_load(game, &game->three, "./assets/3.xpm");
	texture_load(game, &game->four, "./assets/4.xpm");
	texture_load(game, &game->five, "./assets/5.xpm");
	texture_load(game, &game->six, "./assets/6.xpm");
	texture_load(game, &game->seven, "./assets/7.xpm");
	texture_load(game, &game->eight, "./assets/8.xpm");
	texture_load(game, &game->nine, "./assets/9.xpm");
	texture_load(game, &game->zero, "./assets/0.xpm");
	texture_load(game, &game->black, "./assets/black.xpm");
	texture_load(game, &game->grave, "./assets/grave.xpm");
	texture_init2(game);
}

static void	find_coords(t_game *game)
{
	t_iters	iters;

	init_iters(&iters);
	while (iters.i < game->gamestatus.width)
	{
		while (iters.j < game->gamestatus.height)
		{
			if (game->gamestatus.map[iters.i][iters.j] == 'E')
			{
				game->exit.x = iters.j;
				game->exit.y = iters.i;
			}
			if (game->gamestatus.map[iters.i][iters.j] == 'P')
			{
				game->player.x = iters.j;
				game->player.y = iters.i;
				game->gamestatus.map[iters.i][iters.j] = '0';
			}
			++iters.j;
		}
		iters.j = 0;
		++iters.i;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->display = mlx_new_window(game->mlx, game->gamestatus.height * 50,
			(game->gamestatus.width + 1) * 50, "so_long");
	texture_init(game);
	find_coords(game);
}
