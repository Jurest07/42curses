/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <lis@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:08:27 by lis               #+#    #+#             */
/*   Updated: 2021/10/26 02:38:37 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(char const *fmt, ...);
int	ft_fprintf(int fd, char const *fmt, ...);
int	ft_vfprintf(int fd, char const *fmt, va_list args);

#endif
