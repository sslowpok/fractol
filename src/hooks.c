/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:49 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/19 16:37:36 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"

int	close_win(int keycode, t_win *list)
{
	(void)list;
	exit(0);
	return (keycode);
}

int	key_hook(int keycode, t_win *list)
{
	t_fractal	*fractal;

	mlx_clear_window(list->mlx, list->mlx_win);
	fractal = list->fractal;
	if (keycode == KEY_ESC)
		close_win(keycode, list);
	else if (keycode == KEY_A)
		fractal->x0 -= 50;
	else if (keycode == KEY_D)
		fractal->x0 += 50;
	else if (keycode == KEY_W)
		fractal->y0 += 50;
	else if (keycode == KEY_S)
		fractal->y0 -= 50;
	else if (keycode == KEY_C)
	{
		fractal->r += 20;
		fractal->g += 15;
		fractal->b += 3;
	}
	draw_fractal(list);
	return (keycode);
}

static void	zoom(int button, t_fractal *fractal)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (button == MOUSE_SCROLL_UP)
			fractal->scale += (50);
		else if (button == MOUSE_SCROLL_DOWN && fractal->scale > 0)
			fractal->scale -= (50);
	}
}

int	mouse(int button, int x, int y, t_win *list)
{
	mlx_clear_window(list->mlx, list->mlx_win);
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (button == MOUSE_SCROLL_UP)
		{
			list->fractal->x0 += (x - WIDTH / 2) * 0.4;
			list->fractal->y0 -= (y - HEIGHT / 2) * 0.4;
		}
		else if (button == MOUSE_SCROLL_DOWN)
		{
			list->fractal->x0 -= (WIDTH / 2 - x) * 0.4;
			list->fractal->y0 += (HEIGHT / 2 - y) * 0.4;
		}
		zoom(button, list->fractal);
	}
	draw_fractal(list);
	return (0);
}
