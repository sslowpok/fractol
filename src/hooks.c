/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:49 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/14 09:36:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"

int	close_win(int keycode, t_win *list)
{
	exit(0);
	(void)list;
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
	if (keycode == KEY_ESC)
		close_win(keycode, list);
	draw_fractal(list);
	return (keycode);
}