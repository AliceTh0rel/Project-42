/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:43:51 by althorel          #+#    #+#             */
/*   Updated: 2025/08/11 12:27:37 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = a;
	min = tmp;
	while (tmp)
	{
		if (min->nbr > tmp->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	which_action(int ra, int rra, int ra_target, int rra_target)
{
	int	best_cost;
	int	which_one;

	which_one = 1;
	best_cost = ra + ra_target;
	if (best_cost > rra + rra_target)
	{
		which_one = 2;
		best_cost = rra + rra_target;
	}
	if (best_cost > ra + rra_target)
	{
		which_one = 3;
		best_cost = ra + rra_target;
	}
	if (best_cost > rra + ra_target)
	{
		which_one = 4;
		best_cost = rra + ra_target;
	}
	return (which_one);
}

int	action(t_stack *stack, t_stack **a, t_stack **b)
{
	int	ra;
	int	rra;
	int	ra_target;
	int	rra_target;

	if (!stack || !stack->target)
		return (0);
	ra = cost_ra(stack);
	rra = cost_rra(stack, *a);
	ra_target = cost_ra(stack->target);
	rra_target = cost_rra(stack->target, *b);
	return (which_action(ra, rra, ra_target, rra_target));
}

void	end_of_sort(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	if (min->index == 1)
		return ;
	if (cost_ra(min) < cost_rra(min, *a))
	{
		while (min->index != 1)
		{
			ra(a);
			give_index(*a);
		}
	}
	else
	{
		while (min->index != 1)
		{
			rra(a);
			give_index(*a);
		}
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	pb(a, b);
	if (ft_lstsize(*a) != 3)
		pb(a, b);
	while (*a)
	{
		move_stack(a, b);
		pb(a, b);
	}
	while (*b)
		pa(b, a);
	give_index(*a);
	end_of_sort(a);
}
