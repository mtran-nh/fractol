/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:49:46 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/14 22:43:21 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

#define ERROR_MSG "enter wrong name"

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

t_complex	sum_cmp(t_complex z1, t_complex z2);
t_complex	sqrt_cmp(t_complex z);
double		ft_atodbl(char *s);

#endif