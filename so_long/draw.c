/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:00:02 by slight            #+#    #+#             */
/*   Updated: 2022/03/24 12:19:05 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

char*	ft_inttostr(unsigned int num)
{
	char			*str;
	unsigned int	tmp;
	int				i;

	tmp = num;
	i = 0;
	if (tmp == 0)
		++i;
	while (tmp != 0)
	{
		++i;
		tmp /= 10;
	}
	str = (char *)malloc(sizeof(*str) * (i + 1));
	str[i] = 0;
	while (i > 0)
	{
		str[i - 1] = num % 10 + '0';
		num /= 10;
		--i;
	}
	return (str);
}

static void	draw2(t_game *game, int i, int j, int keycode)
{
	if (game->gamestatus.map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->display, game->wall, j*50, i*50);
	if (game->gamestatus.map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->display, game->floor, j*50, i*50);
	if (game->gamestatus.map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->display, game->youtube, j*50, i*50);
	if (j == game->player.x && i == game->player.y && (keycode == 100 || keycode == 0))
		mlx_put_image_to_window(game->mlx, game->display, game->k_right, j*50, i*50);
	if (j == game->player.x && i == game->player.y && keycode == 119)
		mlx_put_image_to_window(game->mlx, game->display, game->k_up, j*50, i*50);
	if (j == game->player.x && i == game->player.y && keycode == 115)
		mlx_put_image_to_window(game->mlx, game->display, game->k_down, j*50, i*50);
	if (j == game->player.x && i == game->player.y && keycode == 97)
		mlx_put_image_to_window(game->mlx, game->display, game->k_left, j*50, i*50);
	if (game->gamestatus.map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->display, game->like, j*50, i*50);
	if (j == game->player.x && i == game->player.y && game->gamestatus.die == 1)
		mlx_put_image_to_window(game->mlx, game->display, game->grave, j*50, i*50);
}

void	draw_digit(t_game *game, char move, int i, int j)
{
	if (move == 'b')
		mlx_put_image_to_window(game->mlx, game->display, game->black, j, i);
	if (move == '0')
		mlx_put_image_to_window(game->mlx, game->display, game->zero, j, i);
	if (move == '1')
		mlx_put_image_to_window(game->mlx, game->display, game->one, j, i);
	if (move == '2')
		mlx_put_image_to_window(game->mlx, game->display, game->two, j, i);
	if (move == '3')
		mlx_put_image_to_window(game->mlx, game->display, game->three, j, i);
	if (move == '4')
		mlx_put_image_to_window(game->mlx, game->display, game->four, j, i);
	if (move == '5')
		mlx_put_image_to_window(game->mlx, game->display, game->five, j, i);
	if (move == '6')
		mlx_put_image_to_window(game->mlx, game->display, game->six, j, i);
	if (move == '7')
		mlx_put_image_to_window(game->mlx, game->display, game->seven, j, i);
	if (move == '8')
		mlx_put_image_to_window(game->mlx, game->display, game->eight, j, i);
	if (move == '9')
		mlx_put_image_to_window(game->mlx, game->display, game->nine, j, i);
}

static void	draw_move(t_game *game, int i, int j)
{
	char* move;
	int len;
	int k;

	k = 0;
	i = i * 50;
	move = ft_inttostr(game->gamestatus.count_press);
	len = ft_strlen(move);
	j = (game->gamestatus.height - len) * 50;
	while (k < len)
	{
		draw_digit(game, move[k], i, j);
		++k;
		j = j + 50;
	}
	j = 0;
	free(move);
	draw_c(game, i, j);
}

void	draw(t_game *game, int keycode)
{
	int i;
	int j;

	i = game->gamestatus.width;
	j = -1;
	while (j++ < game->gamestatus.height)
		mlx_put_image_to_window(game->mlx, game->display, game->black, j * 50, i * 50);
	j = 0;
	i = 0;
	while (i < game->gamestatus.width)
	{
		j = 0;
		while (j < game->gamestatus.height)
		{
			draw2(game, i, j, keycode);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(game->mlx, game->display, game->zero, (j - 1) * 50, i * 50);
	draw_move(game, i, j);
}
