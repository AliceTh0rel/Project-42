/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:48:17 by althorel          #+#    #+#             */
/*   Updated: 2025/09/08 11:38:55 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->color_mode = 0;
	fractal->color_shift = 0;
	fractal->max_x = 2;
	fractal->min_x = -2;
	fractal->max_y = 2;
	fractal->min_y = -2;
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (!fractal->mlx_connect)
		error("MALLOC ERROR\n");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connect,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		error("MALLOC ERROR\n");
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		error("MALLOC ERROR\n");
	}
	fractal->img.pxl_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	my_events(fractal);
	init_data(fractal);
}
