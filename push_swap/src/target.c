/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:26:27 by althorel          #+#    #+#             */
/*   Updated: 2025/08/11 12:39:28 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	choose_target(t_stack *a, t_stack *b,
	t_stack **target_min, t_stack **target_max)
{
	if (b->nbr < a->nbr)
	{
		if (!(*target_min) || b->nbr > (*target_min)->nbr)
			(*target_min) = b;
	}
	if (!(*target_max) || b->nbr > (*target_max)->nbr)
		(*target_max) = b;
}

void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*target_min;
	t_stack	*target_max;

	tmp_a = a;
	while (tmp_a)
	{
		target_min = NULL;
		target_max = NULL;
		tmp_b = b;
		while (tmp_b)
		{
			choose_target(tmp_a, tmp_b, &target_min, &target_max);
			tmp_b = tmp_b->next;
		}
		if (target_min)
			tmp_a->target = target_min;
		else
			tmp_a->target = target_max;
		tmp_a = tmp_a->next;
	}
}
