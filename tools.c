/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:46:27 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 16:20:03 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len = len + 1;
	}
	return (len);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i = i + 1;
	}
	if (ft_strlen(s1) > ft_strlen(s2))
		return (str1[ft_strlen(s2)]);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-str2[ft_strlen(s1)]);
	return (0);
}

int			julia(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;

	iterations = 1;
	z.re = x / config->zoom + config->x;
	z.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 2.0)
	{
		z = add(multiply(z, z), config->c);
		iterations++;
	}
	return (iterations);
}

int			mandelbrot(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 2.0)
	{
		z = add(multiply(z, z), c);
		iterations++;
	}
	return (iterations);
}

void		draw(t_config *config)
{
	int		i;
	int		j;
	int		iter;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			iter = config->fractal(i, j, config);
			if (iter == config->iterations)
				mlx_pixel_put(config->mlx_ptr, config->mlx_win, i, j, 0x0);
			else
				mlx_pixel_put(config->mlx_ptr, config->mlx_win, i, j, iter * 500);
			j++;
		}
		i++;
	}
}