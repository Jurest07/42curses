/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:00:02 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:00:03 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	ft_putnbr(unsigned int num)
{
	char			*str;
	unsigned int	tmp;
	int				i;

	tmp = num;
	i = 0;
	while (tmp != 0)
	{
		++i;
		tmp /= 10;
	}
	str = (char *)malloc(sizeof(*str) * (i + 2));
	str[i + 1] = 0;
	str[i] = '\n';
	while (i > 0)
	{
		str[i - 1] = num % 10 + '0';
		num /= 10;
		--i;
	}
	write(1, str, ft_strlen(str));
	free(str);
}

static void	draw_square(t_game *game, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(game->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_game *game, int i, int j)
{
	if (game->exit.x == i && game->exit.y == j)
		draw_square(game, game->youtube, i * 40, j * 40);
	if (game->gamestatus.map[j][i] == 'c'
		|| game->gamestatus.map[j][i] == 'c')
		draw_square(game, game->like, i * 40, j * 40);
	if (game->player.x == i && game->player.y == j)
		draw_square(game, game->kuplinov, i * 40, j * 40);
}

static void	draw_map(t_game *game)
{
	int				i;
	int				j;

	j = 0;
	while (j < game->gamestatus.width)
	{
		i = 0;
		while (i < game->gamestatus.height)
		{
			if (game->gamestatus.map[j][i] == '1')
			{
				draw_square(game, game->wall, i * 40, j * 40);
			}
			else
				draw_square(game, game->floor, i * 40, j * 40);
			draw_env(game, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_game *game)
{
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->display, game->mlx_img, 0, 0);
}
