/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:49 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/14 18:42:22 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"

// void	ft_exit(void)
// {
// 	exit(0);
// }

int	close_win(int keycode, t_win *list)
{
	ft_printf("exit\n");
	(void)list;
	exit(0);
	return (keycode);
}

//void	move(int keycode, t_fractal *fractal)
//{
//	double	shift;

//	shift = (2.0 + 2.0) * SHIFT_SCALE;
//	if (keycode == KEY_A)
//	{
//		fractal->max_iter
//	}
//}

int	key_hook(int keycode, t_win *list)
{
	t_fractal	*fractal;

	fractal = list->fractal;
	ft_printf("key_hook %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		close_win(keycode, list);
		return (0);
	}
	else
		return (keycode);
	draw_fractal(list);
	return (keycode);
}

static void	zoom(int button, t_fractal *fractal)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (button == MOUSE_SCROLL_UP)
			fractal->scale *= 1.05;
		else if (button == MOUSE_SCROLL_DOWN)
			fractal->scale *= 0.95;
	}
}

int	mouse(int button, int x, int y, t_win *list)
{
	ft_printf("mouse hook\n");
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		zoom(button, list->fractal);
		draw_fractal(list);
	}
	// (void)x;
	// (void)y;
	
	return (0);
}