/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 19:18:27 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/26 15:20:26 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		print_scene(t_config *config)
{
	int		fd;
	int		width;
	int		height;
	int		size;

	fd = open("scene.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return ;
	width = WINDOW_WIDTH;
	height = -WINDOW_HEIGHT;
	size = width * -height * 4 + 54;
	write(fd, "\x42\x4d", 2);
	write(fd, &size, 4);
	write(fd, "\x0\x0\x0\x0\x36\x0\x0\x0\x28\x0\x0\x0", 12);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, "\x1\x0\x20\x0\x0\x0\x0\x0", 8);
	size -= 54;
	write(fd, &size, 4);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, "\x0\x0\x0\x0\x0\x0\x0\x0", 8);
	write(fd, config->image.data, size);
	close(fd);
}
