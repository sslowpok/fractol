/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:03:28 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/14 09:27:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}



int	fractal_iter(t_fractal *fractal, double x, double y)
{
	double	c_re;
	double	c_im;
	double	tmp_re;
	double	tmp_im;
	int		i;

	if (fractal->name == MANDELBROT)
	{
		c_re = x;
		c_im = y;
	}
	 else if (fractal->name == JULIA)
	{
		c_re = 0;
		c_im = 0;
	}
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

void	draw_fractal(t_win *list)
{
	int			i;
	int			j;
	double		x;
	double		y;
	int			iter;

	i = 0;
	while (i++ < WIDTH)
	{
		j = 0;
		while (j++ < HEIGHT)
		{
			x = (i - 500) / (double) 250;
			y = (500 - j) / (double) 250;
			iter = fractal_iter(list->fractal, x, y);
			my_mlx_pixel_put(list, i, j, 1375 * iter);
		}
	}
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, 0, 0);
	
}