/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:05:43 by althorel          #+#    #+#             */
/*   Updated: 2025/05/12 12:38:02 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = current;
	}
	*lst = NULL;
}
/*
void	del(void *ptr)
{
	free(ptr);
}
	
int main(void)
{
	t_list 	*lst = NULL;
	t_list	*node1 = ft_lstnew("OK1");
	t_list	*node2 = ft_lstnew("OK2");
	t_list	*node3 = ft_lstnew("OK3");
	ft_lstadd_front(&lst, node1);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node3);
	printf("%d", ft_lstsize(lst));
	ft_lstclear(&lst, &del);
	if (!lst)
	printf("ok");
	else
	printf("pas ok");
	return (0);
}
*/
