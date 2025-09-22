/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:08:11 by althorel          #+#    #+#             */
/*   Updated: 2025/09/02 16:53:50 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

long	ft_mini_atoi(const char *str, long result)
{
	while (*str >= '0' && *str <= '9')
	{
			result = result * 10 + *str - '0';
			str++;
	}
	return (result);
}

double	ft_fract_atoi(const char *str, double fract_result)
{
	double	pow;

	pow = 1;
	while (*str >= '0' && *str <= '9')
	{
		pow /= 10;
		fract_result = fract_result + (*str++ - '0') * pow;
	}
	return (fract_result);
}

double	ft_atodbl(const char *str)
{
	int		sign;
	long	result;
	double	fract_result;

	result = 0;
	fract_result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = ft_mini_atoi(str, result);
	while (*str != '.')
		str++;
	if (*str == '.')
		str++;
	fract_result = ft_fract_atoi(str, fract_result);
	return ((result + fract_result) * sign);
}
