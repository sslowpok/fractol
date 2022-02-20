/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:27:58 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/20 16:43:39 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error.h"

void	argc_check(int argc)
{
	if (argc != 2)
	{
		ft_printf("Invalid input.\n");
		exit (INVALID_DATA);
	}
}

static t_win	*new_image(t_win *list)
{
	list->img = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	if (!list->img)
		exit (INIT_ERROR);
	list->addr = mlx_get_data_addr(list->img, &list->bpp, \
				&list->line_length, &list->endian);
	if (!list->addr)
		exit (INIT_ERROR);
	return (list);
}

void	fractal_name(int argc, char **argv, t_fractal *fractal)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		argc_check(argc);
		fractal->name = MANDELBROT;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->name = JULIA;
		julia_arg(argc, argv, fractal);
	}
	else if (ft_strcmp(argv[1], "ship") == 0)
		fractal->name = SHIP;
}

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit (BAD_MEMALLOC);
	fractal->max_iter = MAX_ITER;
	fractal->scale = 250;
	fractal->x0 = -500;
	fractal->y0 = 500;
	fractal->r = 5;
	fractal->g = 50;
	fractal->b = 20;
	fractal_name(argc, argv, fractal);
	fractal->zoom_in_scale = 50;
	fractal->zoom_out_scale = 50;
	return (fractal);
}

void	new_window(int argc, char **argv)
{
	t_win	*list;

	list = malloc(sizeof(t_win));
	if (!list)
		exit(BAD_MEMALLOC);
	list->mlx = mlx_init();
	if (!list->mlx)
		exit (INIT_ERROR);
	list->mlx_win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "My fractlolol");
	if (!list->mlx_win)
		exit (INIT_ERROR);
	new_image(list);
	list->fractal = init_fractal(argc, argv);
	mlx_key_hook(list->mlx_win, key_hook, list);
	mlx_hook(list->mlx_win, 17, 0, close_win, list);
	mlx_hook(list->mlx_win, 4, 0, mouse, list);
	mlx_loop(list->mlx);
}
