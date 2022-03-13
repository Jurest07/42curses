/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:00:11 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:02:24 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	texture_load(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

static void	texture_init(t_game *game)
{
	texture_load(game, &game->kuplinov, "./assets/player.xpm");
	texture_load(game, &game->like, "./assets/gas.xpm");
	texture_load(game, &game->youtube, "./assets/helicopter.xpm");
	texture_load(game, &game->wall, "./assets/wall.xpm");
	texture_load(game, &game->floor, "./assets/sand.xpm");
}

static void	find_coords(t_game *game)
{
	t_iters	iters;

	init_iters(&iters);
	while (iters.i < game->gamestatus.width)
	{
		while (iters.j < game->gamestatus.height)
		{
			if (game->gamestatus.map[iters.i][iters.j] == 'E'
			|| game->gamestatus.map[iters.i][iters.j] == 'e')
			{
				game->exit.x = iters.j;
				game->exit.y = iters.i;
			}
			if (game->gamestatus.map[iters.i][iters.j] == 'P'
			|| game->gamestatus.map[iters.i][iters.j] == 'p')
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
	game->display = mlx_new_window(game->mlx, game->gamestatus.height * 40,
			game->gamestatus.width * 40, "so_long");
	game->mlx_img = mlx_new_image(game->mlx, game->gamestatus.height * 40,
			game->gamestatus.width * 40);
	texture_init(game);
	find_coords(game);
}
