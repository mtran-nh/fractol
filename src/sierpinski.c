/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:44:32 by mtran-nh          #+#    #+#             */
/*   Updated: 2025/09/22 17:30:48 by mtran-nh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	point_in_triangle(t_point p, t_point a, t_point b, t_point c)
{
	double	denom;
	double	alpha;
	double	beta;
	double	gamma;

	denom = (b.y - c.y) * (a.x - c.x) + (c.x - b.x) * (a.y - c.y);
	alpha = ((b.y - c.y) * (p.x - c.x) + (c.x - b.x) * (p.y - c.y)) / denom;
	beta = ((c.y - a.y) * (p.x - c.x) + (a.x - c.x) * (p.y - c.y)) / denom;
	gamma = 1 - alpha - beta;
	return (alpha >= 0 && beta >= 0 && gamma >= 0);
}

// 0=x
// 1=y
static void	triangle(t_image *img, t_point pts[3], int color)
{
	int		min[2];
	int		max[2];
	int		x;
	int		y;
	t_point	p;

	min[0] = (int)fmin(fmin(pts[0].x, pts[1].x), pts[2].x);
	max[0] = (int)fmax(fmax(pts[0].x, pts[1].x), pts[2].x);
	min[1] = (int)fmin(fmin(pts[0].y, pts[1].y), pts[2].y);
	max[1] = (int)fmax(fmax(pts[0].y, pts[1].y), pts[2].y);
	y = min[1];
	while (y < max[1])
	{
		x = min[0];
		while (x < max[0])
		{
			p.x = (double)x;
			p.y = (double)y;
			if (point_in_triangle(p, pts[0], pts[1], pts[2]))
				ft_putpixel(x, y, img, color);
			x++;
		}
		y++;
	}
}

static void	get_subtriangle(t_point pts[3], t_point t1[3], t_point t2[3],
		t_point t3[3])
{
	t_point	mid[3];

	mid[0].x = (pts[0].x + pts[1].x) / 2;
	mid[0].y = (pts[0].y + pts[1].y) / 2;
	mid[1].x = (pts[1].x + pts[2].x) / 2;
	mid[1].y = (pts[1].y + pts[2].y) / 2;
	mid[2].x = (pts[2].x + pts[0].x) / 2;
	mid[2].y = (pts[2].y + pts[0].y) / 2;
	t1[0] = pts[0];
	t1[1] = mid[0];
	t1[2] = mid[2];
	t2[0] = mid[0];
	t2[1] = pts[1];
	t2[2] = mid[1];
	t3[0] = mid[2];
	t3[1] = mid[1];
	t3[2] = pts[2];
}

void	sierpinski(t_image *img, t_point pts[3], int depth)
{
	t_point	t1[3];
	t_point	t2[3];
	t_point	t3[3];

	if (depth <= 0)
	{
		triangle(img, pts, WHITE);
		return ;
	}
	get_subtriangle(pts, t1, t2, t3);
	sierpinski(img, t1, depth - 1);
	sierpinski(img, t2, depth - 1);
	sierpinski(img, t3, depth - 1);
}
