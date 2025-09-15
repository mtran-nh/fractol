/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:44:22 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/15 20:36:08 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	handel_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    
    z.x = (scale_num(x, -2, 2, 0, WIDTH));
    z.y = (scale_num(y, 2, -2, 0, HEIGHT));
    
    
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

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
