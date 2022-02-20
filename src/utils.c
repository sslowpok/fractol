/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:39:20 by sslowpok          #+#    #+#             */
/*   Updated: 2022/02/20 16:53:29 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error.h"

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

int	check(char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	if (*str == '.' && i <= 5)
	{
		str++;
		while (ft_isdigit(*str))
		{
			str++;
			i++;
		}
		if (*str == '\0' && i > 0 && i <= 10)
			return (1);
	}
	else if (*str == '\0' && i > 0)
		return (1);
	return (0);
}

void	input_error(void)
{
	ft_printf("Invalid input.\n");
	exit (INVALID_DATA);
}

void	julia_arg(int argc, char **argv, t_fractal *fractal)
{
	int	i;

	i = 2;
	if (argc == 2)
		return ;
	else if (argc == 5)
	{
		while (i < argc)
		{
			if (ft_isdigit(ft_atoi(argv[i])))
				input_error();
			i++;
		}
		fractal->r = ft_atoi(argv[2]);
		fractal->g = ft_atoi(argv[3]);
		fractal->b = ft_atoi(argv[4]);
	}
	else
		input_error();
}
