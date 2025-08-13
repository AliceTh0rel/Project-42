/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:45:23 by althorel          #+#    #+#             */
/*   Updated: 2025/08/11 18:02:33 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char **av, int split_y, int i, t_stack **a)
{
	write(2, "Error\n", 6);
	if (split_y)
		free_split(av);
	if (i)
		free_stack(a);
	exit(EXIT_FAILURE);
}

int	syntaxe(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str || str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	ft_atol_check(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
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

void	check(char **av, t_stack **a, int split_y)
{
	int				i;
	int				j;
	long			n1;
	long			n2;

	i = 0;
	while (av[i])
	{
		if (!syntaxe(av[i]))
			error(av, split_y, i, a);
		if (!ft_atol_check(av[i]))
			error(av, split_y, i, a);
		else
			n1 = ft_atol(av[i]);
		j = i + 1;
		while (av[j])
		{
			n2 = ft_atol(av[j]);
			if (n1 == n2)
				error(av, split_y, i, a);
			j++;
		}
		init_stack_a(a, n1);
		i++;
	}
}
