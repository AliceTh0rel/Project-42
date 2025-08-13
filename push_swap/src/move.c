/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:35:51 by althorel          #+#    #+#             */
/*   Updated: 2025/08/10 19:10:10 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_one(t_stack **a, t_stack **b, t_stack *best)
{
	while (best && best->index != 1 && best->target->index != 1)
	{
		rr(a, b);
		give_index(*a);
		give_index(*b);
	}
	while (best && best->index != 1)
	{
		ra(a);
		give_index(*a);
	}
	while (best && best->target->index != 1)
	{
		rb(b);
		give_index(*b);
	}
}

void	do_two(t_stack **a, t_stack **b, t_stack *best)
{
	while (best && best->index != 1 && best->target->index != 1)
	{
		rrr(a, b);
		give_index(*a);
		give_index(*b);
	}
	while (best && best->index != 1)
	{
		rra(a);
		give_index(*a);
	}
	while (best && best->target->index != 1)
	{
		rrb(b);
		give_index(*b);
	}
}

void	do_three(t_stack **a, t_stack **b, t_stack *best)
{
	while (best && best->index != 1)
	{
		ra(a);
		give_index(*a);
	}
	while (best && best->target->index != 1)
	{
		rrb(b);
		give_index(*b);
	}
}

void	do_four(t_stack **a, t_stack **b, t_stack *best)
{
	while (best && best->index != 1)
	{
		rra(a);
		give_index(*a);
	}
	while (best && best->target->index != 1)
	{
		rb(b);
		give_index(*b);
	}
}

void	move_stack(t_stack **a, t_stack **b)
{
	t_stack	*best;
	int		the_action;

	give_index(*a);
	give_index(*b);
	find_target(*a, *b);
	best = best_move(a, b);
	if (!best)
		return ;
	the_action = action(best, a, b);
	if (the_action == 1)
		do_one(a, b, best);
	if (the_action == 2)
		do_two(a, b, best);
	if (the_action == 3)
		do_three(a, b, best);
	if (the_action == 4)
		do_four(a, b, best);
}
