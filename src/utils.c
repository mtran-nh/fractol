/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:39:42 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/22 17:40:59 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	fmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	fmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_putpixel(int x, int y, t_image *img, int color)
{
	int	pos;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pos = (y * img->line_len) + (x * (img->bitppix / 8));
		*(unsigned int *)(img->pixels_ptr + pos) = color;
	}
}

// 0 for min
// 1 for max
double	scale_num(double unscaled_num, double new[2], double old[2])
{
	return ((unscaled_num - old[0]) * (new[1] - new[0]) / (old[1] - old[0])
		+ new[0]);
}
