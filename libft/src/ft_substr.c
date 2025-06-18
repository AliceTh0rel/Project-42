/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:45:42 by althorel          #+#    #+#             */
/*   Updated: 2025/05/06 13:35:26 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	const char	*str;
	size_t		i;

	i = 0;
	str = &s[i + start];
	if (!s || ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
