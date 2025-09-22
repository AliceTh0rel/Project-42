/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:01:37 by althorel          #+#    #+#             */
/*   Updated: 2025/09/02 15:17:50 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_m_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pxl_ptr + offset) = color;
}

int	which_color(int i, t_fractal *fractal)
{
	int	color;

	color = 0;
	if (fractal->color_mode == 0)
		color = (i * 255 / MAX_ITER) << 16;
	else if (fractal->color_mode == 1)
		color = ((i * 255 / MAX_ITER) << 16)
			| ((i * 128 / MAX_ITER) << 8) | ((i * 64 / MAX_ITER));
	else if (fractal->color_mode == 2)
		color = psy_color1(i, fractal);
	else if (fractal->color_mode == 3)
		color = psy_color2(i, fractal);
	return (color);
}

static void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, "Julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	place_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, fractal->min_x, fractal->max_x, WIDTH) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (map(y, fractal->max_y, fractal->min_y, HEIGHT) * fractal->zoom)
		+ fractal->shift_y;
	mandelbrot_or_julia(&z, &c, fractal);
	while (i < MAX_ITER)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = which_color(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	the_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			place_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connect,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
