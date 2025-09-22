/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psy_color_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:09 by althorel          #+#    #+#             */
/*   Updated: 2025/09/02 15:35:35 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	psy_color1(int i, t_fractal *fractal)
{
	double	t;

	t = (double)((i + fractal->color_shift) % MAX_ITER) / MAX_ITER;
	return (interpolate_color(WHITE, VERT_EAU, fmod(t, 1.0)));
}

int	get_r(int trgb)
{
	return (trgb >> 16 & 0xFF);
}

int	get_g(int trgb)
{
	return (trgb >> 8 & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	interpolate_color(int start, int end, double t)
{
	int	r;
	int	g;
	int	b;

	if (t < 0.5)
	{
		r = map(t, get_r(start), get_r(end), 1);
		g = map(t, get_g(start), get_g(end), 1);
		b = map(t, get_b(start), get_b(end), 1);
	}
	else
	{
		r = map(t, get_r(end), get_r(start), 1);
		g = map(t, get_g(end), get_g(start), 1);
		b = map(t, get_b(end), get_b(start), 1);
	}
	return (r << 16 | g << 8 | b);
}
