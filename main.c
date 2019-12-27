/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:56:24 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/27 14:06:08 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		exit_properly(int status)
{
	if (status == 1)
	{
		write(1, "Usage : ./fractol fractal_name\n", 31);
		write(1, "fractal_name :\n", 15);
		write(1, "\t- Julia\n\t- Mandelbrot\n\t- Tricorn\n\t- Mandelbar\n", 47);
		write(1, "\t- BurningShipPartial\n\t- Buffalo\n\t- Heart\n", 42);
		write(1, "\t- MandelbarVertical\n", 21);
		write(1, "\t- MandelbarHorizontal\n", 23);
	}
	else if (status == 2)
		write(2, "Failed to init mlx.\n", 20);
	else if (status == 3)
		write(2, "Failed to create window.\n", 25);
	else if (status == 4)
		write(2, "Failed to create new image.\n", 28);
	else if (status == 5)
		write(2, "Error while creating thread.\n", 29);
	else if (status == 6)
		write(2, "Error while joining threads.\n", 29);
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
		&& ft_strcmp(av[1], "Tricorn") && ft_strcmp(av[1], "Mandelbar")
		&& ft_strcmp(av[1], "Heart") && ft_strcmp(av[1], "BurningShipPartial")
		&& ft_strcmp(av[1], "Buffalo") && ft_strcmp(av[1], "Mandelbar")
		&& ft_strcmp(av[1], "MandelbarVertical")
		&& ft_strcmp(av[1], "MandelbarHorizontal")))
		exit_properly(1);
	if (!(config->mlx_ptr = mlx_init()))
		exit_properly(2);
	if (!(config->mlx_win = mlx_new_window(config->mlx_ptr,
	WINDOW_WIDTH, WINDOW_HEIGHT, av[1])))
		exit_properly(3);
	if (!(init_image(config->mlx_ptr, &(config->image))))
	{
		mlx_destroy_window(config->mlx_ptr, config->mlx_win);
		exit_properly(4);
	}
}

static void	init_config(int ac, char *av[], t_config *config)
{
	int		i;

	check_errors(ac, av, config);
	i = 0;
	while (i < 50)
	{
		config->color[i] = 1337 * 42 * (i + 1);
		i++;
	}
	config->zoom = 200.0;
	config->iterations = 50;
	config->x = -2.3;
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
