/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:48:10 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/19 16:49:15 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include "../libft/libft.h"

# define WIDTH		800
# define HEIGHT		800
# define MANDELBROT 0
# define JULIA		1
# define SHIP		2
# define MAX_ITER	100

typedef struct s_fractal
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

typedef struct s_win
{
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
int		ft_strcmp(const char *s1, const char *s2);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);

#endif