/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:18:53 by althorel          #+#    #+#             */
/*   Updated: 2025/08/12 11:23:11 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min_value(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*min_value;

	tmp = a;
	min_value = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (min_value->nbr > tmp->nbr)
			min_value = tmp;
		tmp = tmp->next;
	}
	return (min_value);
}

void	sort_five_move(t_stack**a, t_stack **b)
{
	t_stack	*min_value;

	while (ft_lstsize(*a) != 3)
	{
		min_value = find_min_value(*a);
		if (min_value->index <= (ft_lstsize(*a) + 1) / 2)
		{
			while (min_value->index != 1)
			{
				ra(a);
				give_index(*a);
			}
			pb(a, b);
		}
		else
		{
			while (min_value->index != 1)
			{
				rra(a);
				give_index(*a);
			}
			pb(a, b);
		}
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	give_index(*a);
	sort_five_move(a, b);
	if (!stack_sorted(*a))
		sort_three(a);
	if (stack_sorted(*b))
		sb(b);
	pa(b, a);
	pa(b, a);
}
