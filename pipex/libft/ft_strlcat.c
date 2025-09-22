/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:33:28 by althorel          #+#    #+#             */
/*   Updated: 2025/05/01 11:12:53 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;

	lendest = ft_strlen(dest);
	if (!size || size <= lendest)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (i + lendest) < (size - 1))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[i + lendest] = '\0';
	return (lendest + ft_strlen(src));
}
