/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:21:09 by slight            #+#    #+#             */
/*   Updated: 2022/01/14 19:03:38 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int n, int fd)
{
	int		sum;
	int		dell;
	char	temp;

	sum = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n < 0 && !addret(write(fd, "-", 1), &sum))
		return (-1);
	if (n > 0)
		n = -n;
	dell = jrs_power(10, digit_count_of_int(n) - 1);
	while (dell > 0)
	{
		temp = -(n / dell) + 48;
		if (!addret(write(fd, &temp, 1), &sum))
			return (-1);
		n = n % dell;
		dell = dell / 10;
	}
	return (sum);
}

int	print_unsigned_number(t_ui num)
{
	int		dell;
	char	temp;
	int		sum;

	sum = 0;
	if (num == 0)
		return (write(1, "0", 1));
	dell = jrs_power(10, digit_count_of_ui(num) - 1);
	while (dell > 0)
	{
		temp = num / dell + 48;
		if (!addret(write(1, &temp, 1), &sum))
			return (-1);
		num = num % dell;
		dell = dell / 10;
	}
	return (sum);
}

int	ft_putnbr_base(t_ui num, int osn, char *base)
{
	int		razraid;
	int		i;
	t_ui	dell;
	int		temp;

	razraid = s_len(osn, (t_ui) num);
	dell = jrs_power(osn, razraid - 1);
	i = razraid;
	while (i != 0)
	{
		temp = num / dell;
		write(1, &base[temp], 1);
		num = num % dell;
		dell /= osn;
		--i;
	}
	return (razraid);
}

int	print_hex(t_ui num, char c)
{
	if (c == 'X')
		return (ft_putnbr_base(num, 16, "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_putnbr_base(num, 16, "0123456789abcdef"));
	return (0);
}

int	print_pointer(t_ull num, int osn, char *base)
{
	int		razraid;
	int		i;
	t_ull	dell;
	int		temp;

	write(1, "0x", 2);
	razraid = s_len(osn, num);
	dell = jrs_power(osn, razraid - 1);
	i = razraid;
	while (i != 0)
	{
		temp = num / dell;
		write(1, &base[temp], 1);
		num = num % dell;
		dell /= osn;
		--i;
	}
	return (razraid + 2);
}
