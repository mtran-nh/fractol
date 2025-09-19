/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:49:46 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/19 17:42:58 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MSG "enter wrong name"

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_VALUE 4
# define ITERATION 100
# define FRACTAL_COLOR BLACK

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define GRAY 0x808080

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bitppix;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	img;
	int		iteration;
	int		max_value;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

t_complex	sum_cmp(t_complex z1, t_complex z2);
t_complex	sqrt_cmp(t_complex z);
double		ft_atodbl(char *s);
double		scale_num(double unscaled_num, double new[2], double old[2]);

void		init_fractal(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

int			key_handle(int keysym, t_fractal *fractal);
int			close_handle(t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
int			track(int x, int y, t_fractal *fractal);
#endif