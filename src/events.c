/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:53:40 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 22:08:46 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	exit(0);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	if (keysym == XK_Left)
		fractal->move_x += 0.5;
	else if (keysym == XK_Right)
		fractal->move_x -= 0.5;
	else if (keysym == XK_Up)
		fractal->move_y -= 0.5;
	else if (keysym == XK_Down)
		fractal->move_y += 0.5;
	else if (keysym == XK_plus)
		fractal->iteration += 10;
	else if (keysym == XK_minus)
		fractal->iteration -= 10;
	fractal_render(fractal);
	return (0);
}
