/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:48:10 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/16 15:44:52 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
//# include <mlx.h>
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"

# define WIDTH		1000
# define HEIGHT		1000
# define MANDELBROT 0
# define JULIA		1
# define MAX_ITER	100
# define MIN_IM 	-2.0
# define MIN_RE		-2.0
# define MAX_RE		2.0

typedef struct	s_fractal
{
	int		name;
	int		max_iter;
	int		color;
	double	scale;
	double	x0;
	double	y0;
	int		r;
	int		g;
	int		b;
}	t_fractal;

typedef struct	s_win {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_fractal	*fractal;
}		t_win;

void	new_window(int argc, char **argv);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
int		key_hook(int keycode, t_win *list);
void	draw_fractal(t_win *list);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
int		mouse(int keycode, int x, int y, t_win *list);
int		close_win(int keycode, t_win *list);

#endif