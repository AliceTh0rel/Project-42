/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:13:27 by althorel          #+#    #+#             */
/*   Updated: 2025/08/05 14:24:02 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **head)
{
	ft_swap(head);
	ft_printf("sa\n");
}

void	pa(t_stack **src, t_stack **dest)
{
	ft_push(src, dest);
	ft_printf("pa\n");
}

void	ra(t_stack **lst)
{
	ft_rotate(lst);
	ft_printf("ra\n");
}

void	rra(t_stack **lst)
{
	ft_reverse_rotate(lst);
	ft_printf("rra\n");
}
