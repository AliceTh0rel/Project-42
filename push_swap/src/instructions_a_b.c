/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:13:27 by althorel          #+#    #+#             */
/*   Updated: 2025/08/05 14:23:33 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **head_a, t_stack **head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	ft_printf("ss\n");
}

void	rr(t_stack **lst_a, t_stack **lst_b)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	ft_printf("rr\n");
}

void	rrr(t_stack **lst_a, t_stack **lst_b)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	ft_printf("rrr\n");
}
