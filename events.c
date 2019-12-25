/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:00:58 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 16:02:24 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				window_operations(int key, void *param)
{
	t_config	*config;

	config = (t_config*)param;
	if (key == 53)
	{
		mlx_destroy_window(config->mlx_ptr, config->mlx_win);
		exit(0);
	}
	else if (key == 1)
		config->setup = !(config->setup);
	return (0);
}

int				mouse_mouve_operations(int x, int y, void *param)
{
	t_config	*config;

	config = (t_config*)param;
	if (x >= 0 && x <= WINDOW_WIDTH && y >= 0 && y <= WINDOW_HEIGHT)
	{
		if (config->setup)
		{
			config->c.re = 2.0 - (4.0 * (WINDOW_WIDTH - x)) / WINDOW_WIDTH;
			config->c.im = -2.0 + (4.0 * (WINDOW_HEIGHT - y)) / WINDOW_HEIGHT;
		}
	}
	return (0);
}

int				button_operations(int button, int x, int y, void *param)
{
	t_config	*config;

	config = (t_config*)param;
	button = x = y;
	return (0);
}
