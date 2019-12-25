/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:55:41 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 14:14:39 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef	struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef	struct		s_config
{
	void			*mlx_ptr;
	void			*mlx_win;
	double			zoom;
	double			x;
	double			y;
	t_complex		c;
	int				(*fractal_iterations)(t_complex z0, t_complex c);
}					t_config;

t_complex			add(t_complex a, t_complex b);

t_complex			multiply(t_complex a, t_complex b);

#endif
