/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:23:37 by althorel          #+#    #+#             */
/*   Updated: 2025/05/01 11:06:59 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*desti;
	const unsigned char	*source;

	desti = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (source < desti)
	{
		while (size--)
			desti[size] = source[size];
	}
	else
	{
		while (i < size)
		{
			desti[i] = source[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	str[] = "HelloWorld";
	char	str2[] = "HelloWorld";

	ft_memmove(str + 3, str, 5);
	printf("Result: %s\n", str );
	memmove(str2 + 3, str2, 5);
	printf("Result: %s\n", str2);
}
*/
