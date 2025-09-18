/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:44:22 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 22:19:58 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_putpixel(int x, int y, t_image *img, int color)
{
	int	pos;

	pos = (y * img->line_len) + (x * (img->bitppix / 8));
	*(unsigned int *)(img->pixels_ptr + pos) = color;
}

static void	handel_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			paint;

	z.x = 0.0;
	z.y = 0.0;
	c.x = scale_num(x, (double [2]){-2, 2}, (double [2]){0, WIDTH})
		+ fractal->move_x;
	c.y = scale_num(y, (double [2]){2, -2}, (double [2]){0, HEIGHT})
		+ fractal->move_y;
	i = 0;
	while (i < fractal->iteration)
	{
		z = sum_cmp(sqrt_cmp(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->max_value)
		{
			paint = scale_num(i, (double [2]){BLACK, WHITE}, (double [2]){0,
					fractal->iteration});
			ft_putpixel(x, y, &fractal->img, paint);
			return ;
		}
		i++;
	}
	ft_putpixel(x, y, &fractal->img, FRACTAL_COLOR);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handel_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
