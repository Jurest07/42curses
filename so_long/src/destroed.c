/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:32:28 by slight            #+#    #+#             */
/*   Updated: 2022/04/06 16:18:50 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	game_destroy(t_gamestatus *status)
{
	int	i;

	i = 0;
	while (i < status->width)
		free(status->map[i++]);
	free(status->map);
}

static void	root_destroy3(t_game *game)
{
	int	i;

	i = 0;
	if (game->eight != 0)
		mlx_destroy_image(game->mlx, game->eight);
	if (game->nine != 0)
		mlx_destroy_image(game->mlx, game->nine);
	if (game->zero != 0)
		mlx_destroy_image(game->mlx, game->zero);
	if (game->bl != 0)
		mlx_destroy_image(game->mlx, game->bl);
	if (game->gr != 0)
		mlx_destroy_image(game->mlx, game->gr);
	while (i < 6)
	{
		if (game->enemy[i] != 0)
			mlx_destroy_image(game->mlx, game->enemy[i]);
		++i;
	}
}

static void	root_destroy2(t_game *game)
{
	if (game->k_l != 0)
		mlx_destroy_image(game->mlx, game->k_l);
	if (game->k_d != 0)
		mlx_destroy_image(game->mlx, game->k_d);
	if (game->k_up != 0)
		mlx_destroy_image(game->mlx, game->k_up);
	if (game->k_r != 0)
		mlx_destroy_image(game->mlx, game->k_r);
	if (game->one != 0)
		mlx_destroy_image(game->mlx, game->one);
	if (game->two != 0)
		mlx_destroy_image(game->mlx, game->two);
	if (game->three != 0)
		mlx_destroy_image(game->mlx, game->three);
	if (game->four != 0)
		mlx_destroy_image(game->mlx, game->four);
	if (game->five != 0)
		mlx_destroy_image(game->mlx, game->five);
	if (game->six != 0)
		mlx_destroy_image(game->mlx, game->six);
	if (game->seven != 0)
		mlx_destroy_image(game->mlx, game->seven);
	root_destroy3(game);
}

void	root_destroy(t_game *game, char *errmsg, int errnum)
{
	if (game != 0)
	{
		if (game->f != 0)
			mlx_destroy_image(game->mlx, game->f);
		if (game->w != 0)
			mlx_destroy_image(game->mlx, game->w);
		if (game->l != 0)
			mlx_destroy_image(game->mlx, game->l);
		if (game->y != 0)
			mlx_destroy_image(game->mlx, game->y);
		root_destroy2(game);
		if (game->gamestatus.map != 0)
			game_destroy(&(game->gamestatus));
		if (game->d != 0)
			mlx_destroy_window(game->mlx, game->d);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	die(errmsg, errnum);
}

void	die_pls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10000000)
	{
		j = 0;
		while (j < 10000000)
		{
			if (game->gamestatus.die == 1)
				game->gamestatus.die = 1;
			++j;
		}
		++i;
	}
	root_destroy(game, "game over", 1);
}
