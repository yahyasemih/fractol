/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:00:58 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/27 14:46:47 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		handle_moving_iterations(int key, t_config *config)
{
	if (key == 31 && config->iterations > 10)
		config->iterations -= 5;
	else if (key == 34 && config->iterations < 150)
		config->iterations += 5;
	else if (key == 123)
		config->x += (12 / config->zoom);
	else if (key == 124)
		config->x -= (12 / config->zoom);
	else if (key == 125)
		config->y -= (12 / config->zoom);
	else if (key == 126)
		config->y += (12 / config->zoom);
}

static void		handle_colors(int key, t_config *config)
{
	int			i;

	i = 0;
	if (key == 5)
	{
		config->color[0] = 255 * 256;
		while (++i < 50)
			config->color[i] = config->color[i - 1] + 100 * 256;
	}
	else if (key == 8)
		while (i < 50)
			config->color[i++] *= 3;
	else if (key == 11)
	{
		config->color[0] = 255;
		while (++i < 50)
			config->color[i] = config->color[i - 1] + 100 * 256;
	}
	else if (key == 15)
	{
		config->color[0] = 255 * 256 * 256;
		while (++i < 50)
			config->color[i] = config->color[i - 1] + 100 * 256 * 256;
	}
}

int				window_operations(int key, void *param)
{
	t_config	*config;
	int			i;

	config = (t_config*)param;
	i = 0;
	if (key == 1)
		config->setup = !(config->setup);
	else if (key == 5 || key == 8 || key == 11 || key == 15)
		handle_colors(key, config);
	else if (key == 35)
		print_scene(config);
	else if (key == 53)
	{
		mlx_destroy_window(config->mlx_ptr, config->mlx_win);
		mlx_destroy_image(config->mlx_ptr, config->image.mlx_img);
		exit(0);
	}
	else if (key == 31 || key == 34 || (key >= 123 && key <= 126))
		handle_moving_iterations(key, config);
	draw(config);
	return (0);
}

int				mouse_operations(int x, int y, void *param)
{
	t_config	*config;

	config = (t_config*)param;
	if (x >= 0 && x <= WINDOW_WIDTH && y >= 0 && y <= WINDOW_HEIGHT)
	{
		if (config->setup)
		{
			config->c.re = 2.0 - (4.0 * (WINDOW_WIDTH - x)) / WINDOW_WIDTH;
			config->c.im = -2.0 + (4.0 * (WINDOW_HEIGHT - y)) / WINDOW_HEIGHT;
			draw(config);
		}
	}
	return (0);
}

int				button_operations(int button, int x, int y, void *param)
{
	t_config	*config;

	config = (t_config*)param;
	if (button == 4 && config->zoom > 100)
	{
		config->x = x / config->zoom + config->x - x / (config->zoom / 1.2);
		config->y = y / config->zoom + config->y - y / (config->zoom / 1.2);
		(config->zoom) /= 1.2;
	}
	else if (button == 5)
	{
		config->x = x / config->zoom + config->x - x / (config->zoom * 1.2);
		config->y = y / config->zoom + config->y - y / (config->zoom * 1.2);
		(config->zoom) *= 1.2;
	}
	if (button == 4 || button == 5)
		draw(config);
	return (0);
}
