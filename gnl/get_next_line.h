/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:49:08 by slight            #+#    #+#             */
/*   Updated: 2021/11/08 12:27:38 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_string
{
	char	*p_n;
	char	*tmp;
	int		was_read;
}				t_string;

typedef struct	get_next_line
{
	int						fd;
	char					*ost;
	struct get_next_line	*next;
}				GNL;

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#endif
