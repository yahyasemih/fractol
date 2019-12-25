/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:43:07 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 15:39:19 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		add(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_complex		multiply(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = (a.re * b.re - a.im * b.im);
	c.im = (a.re * b.im + a.im * b.re);
	return (c);
}

double			module(t_complex z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
