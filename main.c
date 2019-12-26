/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:56:24 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/26 11:59:08 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	exit_properly(int status)
{
	if (status == 1)
	{
		write(2, "Usage : ./fractol fractal_name\n", 31);
		write(2, "fractal_name : Julia, Mandelbrot.\n", 34);
	}
	else if (status == 2)
		write(2, "Failed to init mlx.\n", 20);
	else if (status == 3)
		write(2, "Failed to create window.\n", 25);
	else if (status == 4)
		write(2, "Failed to create new image.\n", 28);
	exit(status);
}

static int	init_image(void *mlx_ptr, t_image *image)
{
	image->mlx_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(image->mlx_img))
		return (0);
	image->data = mlx_get_data_addr(image->mlx_img, &(image->bits_per_pixel),
		&(image->size_line), &(image->endian));
	if (!(image->data))
		return (0);
	return (1);
}

static void	check_errors(int ac, char *av[], t_config *config)
{
	if (ac != 2
	|| (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot")
		&& ft_strcmp(av[1], "Tricorn") && ft_strcmp(av[1], "Mandelbar")))
		exit_properly(1);
	if (!(config->mlx_ptr = mlx_init()))
		exit_properly(2);
	if (!(config->mlx_win = mlx_new_window(config->mlx_ptr,
	WINDOW_WIDTH, WINDOW_HEIGHT, av[1])))
		exit_properly(3);
	if (!(init_image(config->mlx_ptr, &(config->image))))
		exit_properly(4);
}

static void	init_config(int ac, char *av[], t_config *config)
{
	int		i;

	check_errors(ac, av, config);
	i = 0;
	while (i < 50)
	{
		config->color[i] = 50 * 255 * 255 * i;
		i++;
	}
	config->zoom = 200.0;
	config->iterations = 50;
	config->x = -2.2;
	config->y = -1.5;
	config->setup = 0;
	init_fractals(av, config);
}

int			main(int argc, char *argv[])
{
	t_config	config;

	init_config(argc, argv, &config);
	mlx_mouse_hook(config.mlx_win, button_operations, (void*)(&config));
	mlx_hook(config.mlx_win, 6, 0, mouse_operations, (void*)(&config));
	mlx_hook(config.mlx_win, 2, 0, window_operations, (void*)(&config));
	draw(&config);
	mlx_loop(config.mlx_ptr);
	return (0);
}
