/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:32:28 by slight            #+#    #+#             */
/*   Updated: 2022/03/04 20:33:23 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	game_destroy(t_gamestatus *status, t_game *game)
{
	int	i;

	i = 0;
	while (i < status->width)
		free(status->map[i++]);
	free(status->map);
}

void	root_destroy(t_game *game, char *errmsg, int errnum)
{
	if (game != 0)
	{
		if (game->floor != 0)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->wall != 0)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->like != 0)
			mlx_destroy_image(game->mlx, game->like);
		if (game->youtube != 0)
			mlx_destroy_image(game->mlx, game->youtube);
		if (game->kuplinov != 0)
			mlx_destroy_image(game->mlx, game->kuplinov);
		if (game->mlx_img != 0)
			mlx_destroy_image(game->mlx, game->mlx_img);
		if (game->display != 0)
			mlx_destroy_window(game->mlx, game->display);
		if (game->mlx != 0)
			mlx_destroy_display(game->mlx);
		if (game->gamestatus.map != 0)
			game_destroy(&(game->gamestatus), game);
	}
	die(errmsg, errnum);
}
