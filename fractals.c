/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:36:33 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/26 11:59:25 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_fractals(char *av[], t_config *config)
{
	if (!ft_strcmp(av[1], "Julia"))
	{
		config->fractal = julia;
		config->setup = 1;
		config->c.re = -0.8;
		config->c.im = 0.156;
	}
	else if (!ft_strcmp(av[1], "Mandelbrot"))
		config->fractal = mandelbrot;
	else if (!ft_strcmp(av[1], "Tricorn"))
		config->fractal = tricorn;
	else if (!ft_strcmp(av[1], "Mandelbar"))
		config->fractal = celtic_mandelbar;
}

int				julia(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;

	iterations = 1;
	z.re = x / config->zoom + config->x;
	z.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		z = add(multiply(z, z), config->c);
		iterations++;
	}
	return (iterations);
}

int				mandelbrot(int x, int y, t_config *config)
{
	int			iterations;
	t_complex	z;
	t_complex	c;

	iterations = 1;
	z.re = 0.0;
	z.im = 0.0;
	c.re = x / config->zoom + config->x;
	c.im = y / config->zoom + config->y;
	while (iterations < config->iterations && module(z) < 4.0)
	{
		z = add(multiply(z, z), c);
		iterations++;
	}
	return (iterations);
}

int				tricorn(int x, int y, t_config *config)
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
		z.im = z.im * z.re * -2.0 + c.im;
		z.re = z.re * z.re - holder * holder + c.re;
		iterations++;
	}
	return (iterations);
}

int				celtic_mandelbar(int x, int y, t_config *config)
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
		z.im = z.im * z.re * -2.0 + c.im;
		z.re = fabs(z.re * z.re - holder * holder) + c.re;
		iterations++;
	}
	return (iterations);
}
