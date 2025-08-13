/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:21:43 by althorel          #+#    #+#             */
/*   Updated: 2025/08/11 12:27:50 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*best_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*best_node;
	t_move	move;

	move.best_cost = 0;
	move.first = 1;
	tmp = *a;
	while (tmp)
	{
		move.current_cost = cost_for_one(tmp, a, b);
		if (move.first == 1)
		{
			move.first = 0;
			move.best_cost = move.current_cost;
			best_node = tmp;
		}
		if (move.current_cost < move.best_cost)
		{
			move.best_cost = move.current_cost;
			best_node = tmp;
		}
		tmp = tmp->next;
	}
	return (best_node);
}

int	cost_ra(t_stack *stack)
{
	int	cost;

	if (!stack)
		return (0);
	cost = stack->index - 1;
	return (cost);
}

int	cost_rra(t_stack *stack, t_stack *head)
{
	int	cost;

	if (!stack)
		return (0);
	cost = ft_lstsize(head) - stack->index + 1;
	return (cost);
}

int	cost_for_one(t_stack *stack, t_stack **a, t_stack **b)
{
	int	best_cost;
	int	ra;
	int	rra;
	int	ra_target;
	int	rra_target;

	if (!stack || !stack->target)
		return (INT_MAX);
	ra = cost_ra(stack);
	rra = cost_rra(stack, *a);
	ra_target = cost_ra(stack->target);
	rra_target = cost_rra(stack->target, *b);
	best_cost = ra + ra_target;
	if (best_cost > rra + rra_target)
		best_cost = rra + rra_target;
	if (best_cost > ra + rra_target)
		best_cost = ra + rra_target;
	if (best_cost > rra + ra_target)
		best_cost = rra + ra_target;
	return (best_cost);
}
