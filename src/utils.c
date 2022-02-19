/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:39:20 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/19 16:49:08 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == '\0')
		{
			return (0);
		}
	}
	return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
}
