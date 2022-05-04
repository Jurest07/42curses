/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:57:47 by slight            #+#    #+#             */
/*   Updated: 2022/04/06 16:41:42 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (*c1 || *c2)
	{
		if (*c1 < *c2)
			return (*c1 - *c2);
		if (*c1 > *c2)
			return (*c1 - *c2);
		++c1;
		++c2;
	}
	return (*c1 - *c2);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	isber(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 5)
		return (0);
	if (ft_strcmp(map + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

void	die(char *errmes, int errnum)
{
	int	f;

	if (errmes != 0 && errnum == 0)
		f = write(2, "Error\n", 6);
	if (errmes != 0)
	{
		f = write(2, errmes, ft_strlen(errmes));
		f = write(2, "\n", 1);
	}
	if (f == 0)
		f = 1;
	if (errmes != 0 || errnum != 0)
		exit(1);
	exit(0);

}

int	destroy_hook(t_game *game)
{
	root_destroy(game, 0, 0);
	return (0);
}
