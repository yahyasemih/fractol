/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:46:27 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 15:59:14 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len = len + 1;
	}
	return (len);
}

int		ft_strcmp(const char *s1, const char *s2)
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

int			julia(t_complex z0, t_complex c, int iterations_max)
{
	int			iterations;
	t_complex	z;

	iterations = 1;
	z = z0;
	while (iterations < iterations_max && module(z) < 2.0)
	{
		z = add(multiply(z, z), c);
		iterations++;
	}
	return (iterations);
}

int			mandelbrot(t_complex z0, t_complex c, int iterations_max)
{
	int			iterations;
	t_complex	z;

	iterations = 1;
	z = z0;
	while (iterations < iterations_max && module(z) < 2.0)
	{
		z = add(multiply(z, z), c);
		iterations++;
	}
	return (iterations);
}
