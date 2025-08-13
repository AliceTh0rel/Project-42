/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:24:35 by althorel          #+#    #+#             */
/*   Updated: 2025/08/13 12:29:03 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	choose_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else
		sort_all(a, b);
}

int	check_split(char *str)
{
	if (str[0] == '\0')
		return (0);
	if (str[0] == ' ' && str[1] == '\0')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		split_y;

	a = NULL;
	b = NULL;
	split_y = 0;
	if (ac == 1)
		return (0);
	if (ac == 2 && check_split(av[1]))
	{
		av = split(av[1]);
		split_y = 1;
	}
	else
		av = av + 1;
	check(av, &a, split_y);
	if (split_y)
		free_split(av);
	if (!(stack_sorted(a)))
		choose_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
