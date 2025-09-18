/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:18:43 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/18 22:16:04 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	error_exit(void)
{
	perror("malloc error");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->max_value = MAX_VALUE;
	fractal->iteration = ITERATION;
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handle, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handle, fractal);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!(fractal->mlx_connection))
		error_exit();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (!(fractal->mlx_window))
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_exit();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (!(fractal->img.img_ptr))
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error_exit();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bitppix, &fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
