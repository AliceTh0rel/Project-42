/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:28:08 by althorel          #+#    #+#             */
/*   Updated: 2025/08/12 11:19:23 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_two(t_stack **a)
{
	sa(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if (first > second && first > third && second < third)
		ra(a);
	else if (second > third && first < third)
	{
		rra(a);
		sa(a);
	}
	else if (first < second && first > third && second > third)
		rra(a);
	else if (first > second && first < third && second < third)
		sa(a);
	else
	{	
		sa(a);
		rra(a);
	}
}
