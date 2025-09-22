/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:38:19 by althorel          #+#    #+#             */
/*   Updated: 2025/09/22 19:27:48 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "./../minilibx-linux/mlx.h"
# include "./../minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 40

/* Couleurs */
# define WHITE       0xFFFFFF
# define BLACK       0x000000
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define YELLOW      0xFFFF00
# define CYAN        0x00FFFF
# define MAGENTA     0xFF00FF
# define ORANGE      0xFFA500
# define PURPLE      0x800080
# define PINK        0xFFC0CB
# define DEEP_BLUE   0x000033
# define SKY_BLUE    0x87CEEB
# define LIME        0x32CD32
# define GOLD        0xFFD700
# define VERT_EAU	0x20B2AA

typedef struct s_complex
{
	double		x;
	double		y;
}	t_complex;

typedef struct s_m_img
{
	void		*img_ptr;
	char		*pxl_ptr;
	int			bpp;
	int			endian;
	int			line_len;			
}	t_m_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connect;
	void		*mlx_window;
	t_m_img		img;
	double		escape_value;
	double		shift_x;
	double		shift_y;
	double		julia_x;
	double		julia_y;
	double		zoom;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	int			color_shift;
	int			color_mode;
	int			shade;
}	t_fractal;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

//main
void		error(char *str);

//libft
int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_check_letter(char c, va_list *ap, int *len);
int			ft_printf(const char *format, ...);
long		ft_mini_atoi(const char *str, long result);
void		ft_putchar(char c, int *len);
void		ft_putstr(char *s, int *len);
void		ft_putnbr(int n, int *len);
void		ft_putnbr_long(long int n, int *len);
void		ft_putnbr_unsigned(unsigned int n, int *len);
double		ft_atodbl(const char *str);

//init_window
void		init_data(t_fractal *fractal);
void		init_fractal(t_fractal *fractal);

//init_img
void		my_pixel_put(int x, int y, t_m_img *img, int color);
void		the_fractal(t_fractal *fractal);
int			which_color(int i, t_fractal *fractal);

//calcul
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//hooks
int			close_window(t_fractal *fractal);
int			my_key(int keysym, t_fractal *fractal);
int			my_mouse(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
void		my_events(t_fractal *fractal);

//psy
int			psy_color1(int i, t_fractal *fractal);
int			interpolate_color(int start, int end, double t);
int			psy_color2(int i, t_fractal *fractal);
int			loop_look(t_fractal *fractal);

//hook
// static void ft_hook(void* param);
// int	get_color(int i, int max_iter);

#endif
