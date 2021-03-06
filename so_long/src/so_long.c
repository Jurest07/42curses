/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:08:23 by slight            #+#    #+#             */
/*   Updated: 2022/04/06 16:38:16 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_c(t_game *game, int i, int j)
{
	char	*move;
	int		len;
	int		k;

	k = 0;
	move = ft_inttostr(game->gamestatus.count_c);
	len = ft_strlen(move);
	while (k < len)
	{
		draw_digit(game, move[k], i, j);
		++k;
		j = j + 50;
	}
	free(move);
}

int	enemy_sprite(t_game *game)
{
	static int	i = 0;
	int			k;
	int			l;

	k = 0;
	while (k < game->gamestatus.width)
	{
		l = 0;
		while (l < game->gamestatus.height)
		{
			if (game->gamestatus.map[k][l] == 'G' && (i % 2000 == 0))
				mlx_put_image_to_window(game->mlx, game->d,
					game->enemy[i / 2000], l * 50, k * 50);
			++l;
		}
		++k;
	}
	++i;
	if (i == 12000)
		i = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_gamestatus(&(game.gamestatus));
	if (argc != 2)
		die("Uncorrect number of params! Retry.", 0, game.gamestatus.emptyp);
	if (!isber(argv[1]))
		die("Uncorret format of map(expected .ber)! Rerty.",
			0, game.gamestatus.emptyp);
	parse_map(argv[1], &(game.gamestatus));
	init_game(&game);
	draw(&game, 0);
	mlx_hook(game.d, 2, 1L << 0, key_press, &game);
	mlx_hook(game.d, 17, 1L << 17, destroy_hook, &game);
	mlx_loop_hook(game.mlx, enemy_sprite, &game);
	mlx_loop(game.mlx);
	return (0);
}
