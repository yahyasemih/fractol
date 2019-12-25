/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:55:41 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/25 16:02:29 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900

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
	int				iterations;
	int				setup;
	int				(*fractal)(t_complex z0, t_complex c, int iterations_max);
}					t_config;

t_complex			add(t_complex a, t_complex b);

t_complex			multiply(t_complex a, t_complex b);

double				module(t_complex z);

int					ft_strlen(const char *s);

int					ft_strcmp(const char *s1, const char *s2);

int					julia(t_complex z0, t_complex c, int iterations_max);

int					mandelbrot(t_complex z0, t_complex c, int iterations_max);

int					button_operations(int button, int x, int y, void *param);

int					mouse_mouve_operations(int x, int y, void *param);

int					window_operations(int key, void *param);

#endif
