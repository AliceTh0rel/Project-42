/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:40:25 by althorel          #+#    #+#             */
/*   Updated: 2025/09/02 17:04:24 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(EXIT_FAILURE);
}

int	ft_atoi_check(const char *str, int sign)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

int	ft_atodbl_check(char *str)
{
	int		sign;

	sign = 1;
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!ft_atoi_check(str, sign))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str)
			return (0);
		str++;
	}
	return (1);
}

int32_t	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		|| ((ac == 4 && !ft_strcmp(av[1], "Julia"))
			&& (ft_atodbl_check(av[2]) && ft_atodbl_check(av[3]))))
	{
		fractal.name = av[1];
		if (av[2] && av[3])
		{
			fractal.julia_x = ft_atodbl(av[2]);
			fractal.julia_y = ft_atodbl(av[3]);
		}
		init_fractal(&fractal);
		the_fractal(&fractal);
		mlx_loop_hook(fractal.mlx_connect, &loop_look, &fractal);
		mlx_loop(fractal.mlx_connect);
	}
	else
		error("Entry accepted : Mandelbrot or Julia <value_1> <value_2>\n");
	return (0);
}
