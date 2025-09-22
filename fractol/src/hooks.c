/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:17:14 by althorel          #+#    #+#             */
/*   Updated: 2025/09/02 18:54:41 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connect);
	free(fractal->mlx_connect);
	exit(EXIT_SUCCESS);
}

int	my_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_window(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.25 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.25 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.25 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.25 * fractal->zoom);
	else if (keysym == XK_plus || keysym == XK_equal || keysym == XK_KP_Add)
		fractal->color_mode = (fractal->color_mode + 1) % 4;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->color_mode = (fractal->color_mode - 1 + 4) % 4;
	the_fractal(fractal);
	return (0);
}

int	my_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	re;
	double	im;
	double	new_width;
	double	new_height;

	re = fractal->min_x + (x / (double)WIDTH)
		* (fractal->max_x - fractal->min_x);
	im = fractal->max_y - (y / (double)HEIGHT)
		* (fractal->max_y - fractal->min_y);
	if (button == Button5)
		fractal->zoom = 0.95;
	else if (button == Button4)
		fractal->zoom = 1.05;
	new_width = (fractal->max_x - fractal->min_x) * fractal->zoom;
	new_height = (fractal->max_y - fractal->min_y) * fractal->zoom;
	fractal->min_x = re - (re - fractal->min_x) * fractal->zoom;
	fractal->max_x = fractal->min_x + new_width;
	fractal->max_y = im + (fractal->max_y - im) * fractal->zoom;
	fractal->min_y = fractal->max_y - new_height;
	the_fractal(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "Julia"))
	{
		fractal->julia_x = map(x, -2, +2, WIDTH)
			* fractal->zoom + fractal->shift_x;
		fractal->julia_y = map(y, +2, -2, HEIGHT)
			* fractal->zoom + fractal->shift_y;
		the_fractal(fractal);
	}
	return (0);
}

void	my_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, my_key, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask,
		my_mouse, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask,
		julia_track, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, close_window, fractal);
}
