/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:07:05 by slight            #+#    #+#             */
/*   Updated: 2022/03/25 21:40:47 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	move_up(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y - 1][*x] == '1')
		return ;
	game->gamestatus.count_press++;
	if (game->gamestatus.map[*y - 1][*x] == 'G')
		game->gamestatus.die = 1;
	else if (game->gamestatus.map[*y - 1][*x] == '0')
		game->player.y -= 1;
	else if (game->gamestatus.map[*y - 1][*x] == 'C')
	{
		game->player.y -= 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
	}
	else if (game->gamestatus.map[*y - 1][*x] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
			game->player.y -= 1;
	}
}

void	move_down(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y + 1][*x] == '1')
		return ;
	game->gamestatus.count_press++;
	if (game->gamestatus.map[*y + 1][*x] == 'G')
		game->gamestatus.die = 1;
	else if (game->gamestatus.map[*y + 1][*x] == '0')
		game->player.y += 1;
	else if (game->gamestatus.map[*y + 1][*x] == 'C')
	{
		game->player.y += 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
	}
	else if (game->gamestatus.map[*y + 1][*x] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
			game->player.y += 1;
	}
}

void	move_left(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y][*x - 1] == '1')
		return ;
	game->gamestatus.count_press++;
	if (game->gamestatus.map[*y][*x - 1] == 'G')
		game->gamestatus.die = 1;
	else if (game->gamestatus.map[*y][*x - 1] == '0')
		game->player.x -= 1;
	else if (game->gamestatus.map[*y][*x - 1] == 'C')
	{
		game->player.x -= 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
	}
	else if (game->gamestatus.map[*y][*x - 1] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
			game->player.x -= 1;
	}
}

void	move_right(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y][*x + 1] == '1')
		return ;
	game->gamestatus.count_press++;
	if (game->gamestatus.map[*y][*x + 1] == 'G')
		game->gamestatus.die = 1;
	else if (game->gamestatus.map[*y][*x + 1] == '0')
		game->player.x += 1;
	else if (game->gamestatus.map[*y][*x + 1] == 'C')
	{
		game->player.x += 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
	}
	else if (game->gamestatus.map[*y][*x + 1] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
			game->player.x += 1;
	}
}

int	key_press(int keycode, t_game *game)
{
	game->gamestatus.keycode = keycode;
	if (keycode == 65307)
		root_destroy(game, 0, 0);
	if (keycode == 119)
		move_up(game, &(game->player.x), &(game->player.y));
	if (keycode == 115)
		move_down(game, &(game->player.x), &(game->player.y));
	if (keycode == 97)
		move_left(game, &(game->player.x), &(game->player.y));
	if (keycode == 100)
		move_right(game, &(game->player.x), &(game->player.y));
	draw(game, keycode);
	if (game->gamestatus.die == 1)
		die_pls(game);
	return (0);
}
