/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:52:12 by althorel          #+#    #+#             */
/*   Updated: 2025/05/01 10:48:05 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	desti = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		desti[i] = source[i];
		i++;
	}
	return (dest);
}
