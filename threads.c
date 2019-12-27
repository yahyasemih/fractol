/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:20:13 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/27 13:03:10 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_pixel(int i, int j, int iter, t_config *config)
{
	t_image		*image;

	image = &(config->image);
	if (iter == config->iterations)
	{
		ft_memcpy(image->data + (j * image->size_line + i * 4),
			config->color, 4);
	}
	else
	{
		ft_memcpy(image->data + (j * image->size_line + i * 4),
			config->color + (iter % 50), 3);
		ft_memset(image->data + (j * image->size_line + i * 4 + 3), 0, 1);
	}
}

void			*left_up_thread(void *argument)
{
	int			i;
	int			j;
	int			iter;
	t_config	*config;

	i = 0;
	config = (t_config*)argument;
	while (i < WINDOW_WIDTH / 2)
	{
		j = 0;
		while (j < WINDOW_HEIGHT / 2)
		{
			iter = config->fractal(i, j, config);
			set_pixel(i, j, iter, config);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void			*right_up_thread(void *argument)
{
	int			i;
	int			j;
	int			iter;
	t_config	*config;

	i = WINDOW_WIDTH / 2;
	config = (t_config*)argument;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT / 2)
		{
			iter = config->fractal(i, j, config);
			set_pixel(i, j, iter, config);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void			*left_down_thread(void *argument)
{
	int			i;
	int			j;
	int			iter;
	t_config	*config;

	i = 0;
	config = (t_config*)argument;
	while (i < WINDOW_WIDTH / 2)
	{
		j = WINDOW_HEIGHT / 2;
		while (j < WINDOW_HEIGHT)
		{
			iter = config->fractal(i, j, config);
			set_pixel(i, j, iter, config);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void			*right_down_thread(void *argument)
{
	int			i;
	int			j;
	int			iter;
	t_config	*config;

	i = WINDOW_WIDTH / 2;
	config = (t_config*)argument;
	while (i < WINDOW_WIDTH)
	{
		j = WINDOW_HEIGHT / 2;
		while (j < WINDOW_HEIGHT)
		{
			iter = config->fractal(i, j, config);
			set_pixel(i, j, iter, config);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}
