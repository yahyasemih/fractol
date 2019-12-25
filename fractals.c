/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:36:33 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 16:37:04 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
