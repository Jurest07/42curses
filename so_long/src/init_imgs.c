/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:21:23 by slight            #+#    #+#             */
/*   Updated: 2022/04/06 19:21:02 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_imgs2(t_game *game)
{
	game->enemy[0] = NULL;
	game->enemy[1] = NULL;
	game->enemy[2] = NULL;
	game->enemy[3] = NULL;
	game->enemy[4] = NULL;
	game->enemy[5] = NULL;
}

void	init_imgs(t_game *game)
{
	game->k_r = NULL;
	game->k_l = NULL;
	game->k_d = NULL;
	game->k_up = NULL;
	game->f = NULL;
	game->w = NULL;
	game->l = NULL;
	game->y = NULL;
	game->one = NULL;
	game->two = NULL;
	game->three = NULL;
	game->four = NULL;
	game->five = NULL;
	game->six = NULL;
	game->seven = NULL;
	game->eight = NULL;
	game->nine = NULL;
	game->zero = NULL;
	game->bl = NULL;
	game->gr = NULL;
	init_imgs2(game);
}
