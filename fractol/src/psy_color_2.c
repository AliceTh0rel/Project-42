/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psy_color_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:00:43 by althorel          #+#    #+#             */
/*   Updated: 2025/09/02 16:59:25 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	psy_color2(int i, t_fractal *fractal)
{
	double	t;

	t = (i + fractal->color_shift) % MAX_ITER;
	if (t < MAX_ITER / 2)
		return (map(t, WHITE, VERT_EAU, MAX_ITER));
	else
		return (map(t, VERT_EAU, WHITE, MAX_ITER));
}

int	loop_look(t_fractal *fractal)
{
	if (fractal->color_mode == 2 || fractal->color_mode == 3)
	{
		fractal->color_shift += 1;
		the_fractal(fractal);
	}
	return (0);
}
