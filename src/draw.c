/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:03:28 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/19 17:08:19 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	get_iter(double x, double y, double c_re, double c_im)
{
	int		i;
	double	tmp_re;
	double	tmp_im;

	i = 0;
	while (i < 100 && (x * x + y * y < 4))
	{
		tmp_re = x * x - y * y;
		tmp_im = 2 * x * y;
		x = tmp_re + c_re;
		y = tmp_im + c_im;
		i++;
	}
	return (i);
}

static int	ship_fractal(double x, double y, double c_re, double c_im)
{
	int		i;
	double	tmp_re;
	double	tmp_im;

	i = 0;
	while (i < 100 && (x * x + y * y < 4))
	{
		tmp_re = x * x - y * y;
		tmp_im = 2 * fabs(x * y);
		x = tmp_re + c_re;
		y = tmp_im + c_im;
		i++;
	}
	return (i);
}

int	fractal_iter(t_fractal *fractal, double x, double y)
{
	double	c_re;
	double	c_im;

	c_re = -2.0;
	c_im = -2.0;
	if (fractal->name == MANDELBROT || fractal->name == SHIP)
	{
		c_re = x;
		c_im = y;
		if (fractal->name == SHIP)
			return (ship_fractal(x, y, c_re, c_im));
		else
			return (get_iter(x, y, c_re, c_im));
	}
	else if (fractal->name == JULIA)
	{
		c_re = 0.36;
		c_im = 0.36;
		return (get_iter(x, y, c_re, c_im));
	}
	return (0);
}

static int	get_color(int iter, t_win *list)
{
	return (((255 - iter * list->fractal->r) << 16) + \
			((255 - iter * list->fractal->g) << 8) + \
			(255 - iter * list->fractal->b));
}

void	draw_fractal(t_win *list)
{
	int			i;
	int			j;
	double		x;
	double		y;
	int			iter;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			x = (double)(i + list->fractal->x0) / list->fractal->scale;
			y = (double)(list->fractal->y0 - j) / list->fractal->scale;
			iter = fractal_iter(list->fractal, x, y);
			my_mlx_pixel_put(list, i, j, get_color(iter, list));
		}
	}
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, 0, 0);
}
