/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:55:41 by yez-zain          #+#    #+#             */
/*   Updated: 2019/12/26 12:34:43 by yez-zain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <pthread.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600

typedef	struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef	struct		s_image
{
	void			*mlx_img;
	char			*data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef	struct		s_config
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_image			image;
	double			zoom;
	double			x;
	double			y;
	t_complex		c;
	int				iterations;
	int				setup;
	int				color[50];
	int				(*fractal)(int x, int y, struct s_config *config);
}					t_config;

t_complex			add(t_complex a, t_complex b);

t_complex			multiply(t_complex a, t_complex b);

double				module(t_complex z);

int					ft_strlen(const char *s);

int					ft_strcmp(const char *s1, const char *s2);

void				*ft_memset(void *b, int c, size_t len);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				init_fractals(char *av[], t_config *config);

int					julia(int x, int y, t_config *config);

int					mandelbrot(int x, int y, t_config *config);

int					tricorn(int x, int y, t_config *config);

int					celtic_mandelbar(int x, int y, t_config *config);

void				draw(t_config *config);

void				exit_properly(int status);

int					button_operations(int button, int x, int y, void *param);

int					mouse_operations(int x, int y, void *param);

int					window_operations(int key, void *param);

void				print_scene(t_config *config);

void				*left_up_thread(void *argument);

void				*right_up_thread(void *argument);

void				*left_down_thread(void *argument);

void				*right_down_thread(void *argument);

#endif
