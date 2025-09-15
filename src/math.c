/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:28:18 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/15 20:23:48 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	sum_cmp(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	sqrt_cmp(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_atodbl(char *s)
{
	long	int_part;
	double	dec_part;
	int		sign;
	double	pow;

	int_part = 0;
	dec_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		dec_part = dec_part + (*s++ - 48) * pow;
	}
	return ((int_part + dec_part) * sign);
}

double	scale_num(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((unscaled_num - old_min) * (new_max - new_min) / (old_max - old_min)
		+ new_min);
}

