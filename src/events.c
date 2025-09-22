/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:53:40 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/19 17:56:40 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	if (keysym == XK_Left)
		fractal->move_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->move_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->move_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->move_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iteration += 10;
	else if (keysym == XK_minus && fractal->iteration > 10)
		fractal->iteration -= 10;
	fractal_render(fractal);
	return (0);
}

// khong co x va y thi sai prototype->segfault
int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5 && fractal->zoom > 0.0001)
		fractal->zoom *= 0.95;
	else if (button == Button4 && fractal->zoom < 1000)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = scale_num(x, (double [2]){-2, 2}, (double [2]){0,
				WIDTH}) * fractal->zoom + fractal->move_x;
		fractal->julia_y = scale_num(y, (double [2]){2, -2}, (double [2]){0,
				HEIGHT}) * fractal->zoom + fractal->move_y;
		fractal_render(fractal);
	}
	return (0);
}
