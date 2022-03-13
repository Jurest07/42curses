/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_press.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:07:05 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:08:01 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	move_up(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y - 1][*x] == '0')
	{
		game->player.y -= 1;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y - 1][*x] == 'c'
	|| game->gamestatus.map[*y - 1][*x] == 'C')
	{
		game->player.y -= 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y - 1][*x] == 'e'
	|| game->gamestatus.map[*y - 1][*x] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
		{
			game->player.y -= 1;
			ft_putnbr(game->gamestatus.count_press++);
		}
	}
}

void	move_down(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y + 1][*x] == '0')
	{
		game->player.y += 1;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y + 1][*x] == 'c'
	|| game->gamestatus.map[*y + 1][*x] == 'C')
	{
		game->player.y += 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y + 1][*x] == 'e'
	|| game->gamestatus.map[*y + 1][*x] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
		{
			game->player.y += 1;
			ft_putnbr(game->gamestatus.count_press++);
		}
	}
}

void	move_left(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y][*x - 1] == '0')
	{
		game->player.x -= 1;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y][*x - 1] == 'c'
	|| game->gamestatus.map[*y][*x - 1] == 'C')
	{
		game->player.x -= 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y][*x - 1] == 'e'
	|| game->gamestatus.map[*y][*x - 1] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
		{
			game->player.x -= 1;
			ft_putnbr(game->gamestatus.count_press++);
		}
	}
}

void	move_right(t_game *game, int *x, int *y)
{
	if (game->gamestatus.map[*y][*x + 1] == '0')
	{
		game->player.x += 1;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y][*x + 1] == 'c'
	|| game->gamestatus.map[*y][*x + 1] == 'C')
	{
		game->player.x += 1;
		game->gamestatus.map[*y][*x] = '0';
		--game->gamestatus.count_c;
		ft_putnbr(game->gamestatus.count_press++);
	}
	else if (game->gamestatus.map[*y][*x + 1] == 'e'
	|| game->gamestatus.map[*y][*x + 1] == 'E')
	{
		if (game->gamestatus.count_c == 0)
			root_destroy(game, 0, 0);
		else
		{
			game->player.x += 1;
			ft_putnbr(game->gamestatus.count_press++);
		}
	}
}

int	key_press(int keycode, t_game *game)
{
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
	draw(game);
	return (0);
}
