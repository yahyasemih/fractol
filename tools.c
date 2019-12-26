/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:46:27 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/26 12:46:24 by yez-zain         ###   ########.fr       */
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

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i = i + 1;
	}
	return (b);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i = i + 1;
	}
	return (dst);
}

void		exit_properly(int status)
{
	if (status == 1)
	{
		write(2, "Usage : ./fractol fractal_name\n", 31);
		write(2, "fractal_name : Julia, Mandelbrot, Tricorn, Mandelbar\n", 53);
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

void		draw(t_config *config)
{
	pthread_t	thread[4];
	int			i;

	if (pthread_create(thread, NULL, left_up_thread, config) == -1)
		exit_properly(5);
	if (pthread_create(thread + 1, NULL, right_up_thread, config) == -1)
		exit_properly(5);
	if (pthread_create(thread + 2, NULL, left_down_thread, config) == -1)
		exit_properly(5);
	if (pthread_create(thread + 3, NULL, right_down_thread, config) == -1)
		exit_properly(5);
	i = 0;
	while (i < 4)
	{
		if (pthread_join(thread[i], NULL))
			exit_properly(6);
		i++;
	}
	mlx_clear_window(config->mlx_ptr, config->mlx_win);
	mlx_put_image_to_window(config->mlx_ptr, config->mlx_win,
		config->image.mlx_img, 0, 0);
}
