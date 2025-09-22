/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:44:22 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/22 18:06:00 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	set_c(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handel_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			paint;

	z.x = scale_num(x, (double [2]){-2, 2}, (double [2]){0, WIDTH})
		* fractal->zoom + fractal->move_x;
	z.y = scale_num(y, (double [2]){2, -2}, (double [2]){0, HEIGHT})
		* fractal->zoom + fractal->move_y;
	set_c(&z, &c, fractal);
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

static void	init_triangle(t_point pts[3])
{
	pts[0].x = WIDTH / 2;
	pts[0].y = 50;
	pts[1].x = 50;
	pts[1].y = HEIGHT - 50;
	pts[2].x = WIDTH - 50;
	pts[2].y = HEIGHT - 50;
}

static void	apply_transform(t_point pts[3], t_fractal *fractal)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		pts[i].x = pts[i].x * fractal->zoom + fractal->move_x;
		pts[i].y = pts[i].y * fractal->zoom + fractal->move_y;
	}
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;
	t_point	triangle[3];

	ft_bzero(fractal->img.pixels_ptr, WIDTH * HEIGHT * (fractal->img.bitppix
			/ 8));
	if (!ft_strncmp(fractal->name, "sierpinski", 10))
	{
		init_triangle(triangle);
		apply_transform(triangle, fractal);
		sierpinski(&fractal->img, triangle, DEPTH);
	}
	else
	{
		y = -1;
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				handel_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
