/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:13:27 by althorel          #+#    #+#             */
/*   Updated: 2025/08/07 15:38:19 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **head)
{
	t_stack	*swap;

	swap = (*head)->next;
	(*head)->next = (*head)->next->next;
	swap->next = *head;
	*head = swap;
}

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

t_stack	*ft_last(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = (*lst)->next;
	last = ft_last(*lst);
	last->next = *lst;
	(*lst)->next = NULL;
	*lst = tmp;
}

void	ft_reverse_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*before_last;

	before_last = *lst;
	while (before_last->next->next)
		before_last = before_last->next;
	last = ft_last(*lst);
	before_last->next = NULL;
	last->next = *lst;
	*lst = last;
}
