/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:27:58 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/13 17:57:45 by sslowpok         ###   ########.fr       */
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

static void	new_image(t_win *list)
{
	list->img = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	if (!list->img)
		exit (INIT_ERROR);
	list->addr = mlx_get_data_addr(list->img, &list->bpp, \
				&list->line_length, &list->endian);
	if (!list->addr)
		exit (INIT_ERROR);
}

void	fractal_name(int argc, char **argv, t_fractal *fractal)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		argc_check(argc);
		fractal->name = MANDELBROT;
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		fractal->name = JULIA;
}

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit (BAD_MEMALLOC);
	fractal_name(argc, argv, fractal);
	fractal->max_iter = 100;
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

	
	mlx_loop(list->mlx);
}