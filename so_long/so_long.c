/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:08:23 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 20:09:19 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	init_gamestatus(&(game.gamestatus));
	if (argc != 2)
		die("Неправильное число аргументов! Повторите потыпку.", 0);
	if (!isber(argv[1]))
		die("Неправильный формат карты(ожидалось .ber)! Повторите попытку.", 0);
	parse_map(argv[1], &(game.gamestatus));
	init_game(&game);
	draw(&game);
	mlx_hook(game.display, 2, 1L << 0, key_press, &game);
	mlx_hook(game.display, 17, 1L << 17, destroy_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
