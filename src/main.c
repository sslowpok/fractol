/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:47:59 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/13 17:59:53 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// int	ft_fractal_mandelbrot(double _x, double _y)
// {
// 	double c_re = _x;
// 	double c_im = _y;

// 	int i = 0;
// 	_x = 0;
// 	_y = 0;
// 	while (i < 100 && (_x * _x + _y * _y < 4))
// 	{
// 		double tmp_re = _x * _x - _y * _y;
// 		double tmp_im = 2 * _x * _y;
// 		_x = tmp_re + c_re;
// 		_y = tmp_im + c_im;
// 		i++;
// 	}
// 	return i;
// }

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_win	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	// img.mlx = mlx_new_image(mlx, 1000, 1000);
	// img.addr = mlx_get_data_addr(img.mlx, &img.bpp, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	// for (int i = 0; i < 1000; i++)
	// {
	// 	for (int j = 0; j < 1000; j++)
	// 	{
	// 		double _x = (-500 + i) / (double) 250;
	// 		double _y = (500 - j) / (double) 250;
	// 		int iter = ft_fractal_mandelbrot(_x, _y);
	// 		if (iter == 100)
	// 			my_mlx_pixel_put(&img, i, j, 55);
	// 	}
	// }

	// mlx_put_image_to_window(mlx, mlx_win, img.mlx, 0, 0);
	// mlx_loop(mlx);


	  
	// надо пофиксить strncmp в либе, чтобы не было сеги
	
	if (argc < 2)
	{
		ft_printf("more params!\n");
		return (0);
	}
	new_window(argc, argv);
	return (0);
}