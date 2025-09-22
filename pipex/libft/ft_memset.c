/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:48:18 by althorel          #+#    #+#             */
/*   Updated: 2025/05/01 12:24:29 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}
/*
#include <unistd.h>

int	main(void)
{
	char	str[] = "Hola Que Tal";
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	write(1, "\n", 1);
	ft_memset(str,'X', 8);
	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return(0);
}
*/