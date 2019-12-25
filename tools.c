/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:46:27 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 18:47:25 by yez-zain         ###   ########.fr       */
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

void		draw(t_config *config)
{
	int		i;
	int		j;
	int		iter;
	t_image	*image;

	i = 0;
	image = &(config->image);
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			iter = config->fractal(i, j, config);
			if (iter == config->iterations)
				ft_memset(image->data + (j * image->size_line + i * 4), 0, 4);
			else
				ft_memcpy(image->data + (j * image->size_line + i * 4),
					config->color + (iter % 50), 4);
			j++;
		}
		i++;
	}
	mlx_clear_window(config->mlx_ptr, config->mlx_win);
	mlx_put_image_to_window(config->mlx_ptr, config->mlx_win,
		image->mlx_img, 0, 0);
}
