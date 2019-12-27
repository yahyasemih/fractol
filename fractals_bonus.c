/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:49:00 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/27 14:02:35 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				buffalo(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	double		holder;
	double		holder2;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		holder = z.re * z.re;
		holder2 = z.im * z.im;
		z.im = z.im * (5 * holder * holder - 10 * holder * holder2
			+ holder2 * holder2) + c.im;
		z.re = fabs(z.re * (holder * holder - 10 * holder * holder2
			+ 5 * holder2 * holder2)) + c.re;
		iterations++;
	}
	return (iterations);
}

int				burning_ship_partial(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	double		holder;
	double		holder2;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		holder = z.re * z.re;
		holder2 = z.im * z.im;
		z.im = z.im * (5 * holder * holder - 10 * holder * holder2
			+ holder2 * holder2) + c.im;
		z.re = fabs(z.re) * (holder * holder - 10 * holder * holder2
			+ 5 * holder2 * holder2) + c.re;
		iterations++;
	}
	return (iterations);
}

int				heart(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	double		holder;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		holder = z.im;
		z.im = fabs(z.re) * z.im * 2.0 + c.im;
		z.re = z.re * z.re - holder * holder + c.re;
		iterations++;
	}
	return (iterations);
}

int				mandelbar_vertical(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	double		holder;
	double		holder2;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		holder = z.re * z.re;
		holder2 = z.im * z.im;
		z.im = -z.im * (5 * holder * holder - 10 * holder * holder2
			+ holder2 * holder2) + c.im;
		z.re = z.re * (holder * holder - 10 * holder * holder2
			+ 5 * holder2 * holder2) + c.re;
		iterations++;
	}
	return (iterations);
}

int				mandelbar_horizontal(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;
	double		holder;
	double		holder2;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		holder = z.re * z.re;
		holder2 = z.im * z.im;
		z.im = z.im * (5 * holder * holder - 10 * holder * holder2
			+ holder2 * holder2) + c.im;
		z.re = -z.re * (holder * holder - 10 * holder * holder2
			+ 5 * holder2 * holder2) + c.re;
		iterations++;
	}
	return (iterations);
}
