/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:13:27 by althorel          #+#    #+#             */
/*   Updated: 2025/08/05 14:24:17 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **head)
{
	ft_swap(head);
	ft_printf("sb\n");
}

void	pb(t_stack **src, t_stack **dest)
{
	ft_push(src, dest);
	ft_printf("pb\n");
}

void	rb(t_stack **lst)
{
	ft_rotate(lst);
	ft_printf("rb\n");
}

void	rrb(t_stack **lst)
{
	ft_reverse_rotate(lst);
	ft_printf("rrb\n");
}
