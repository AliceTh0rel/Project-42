/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:07:06 by althorel          #+#    #+#             */
/*   Updated: 2025/05/01 12:12:59 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n--)
		temp[n] = 0;
}
/*
#include <unistd.h>

int	main(void)
{
	char	*str;
	int		i;

	str = "Hello";
	i = 0;
	while (str)
	{
		write(1, &str[i++], 1);
	}
	write(1, "\n", 1);
	ft_bzero(str, 3);
	while (str)
	{
		write(1, &str[i++], 1);
	}
	return (0);
}
*/
