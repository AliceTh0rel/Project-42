/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:00:10 by althorel          #+#    #+#             */
/*   Updated: 2025/08/10 17:36:29 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	count_word(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (!is_space(*str) && *str)
		{
			count++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	return (count);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*substr(char *str, int start, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len && str[i + start])
	{
		dest[i] = str[i + start];
		i++;
	}
	return (dest[i] = '\0', dest);
}

char	**split(char *str)
{
	char	**tab;
	char	*start;
	int		i;
	int		words;
	int		len;

	i = 0;
	words = count_word(str);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (*str && i < words)
	{
		while (is_space(*str))
			str++;
		start = str;
		while (!is_space(*str) && *str)
			str++;
		len = str - start;
		tab[i] = substr(start, 0, len);
		if (!tab[i])
			return (free_split(tab), NULL);
		i++;
	}
	return (tab[i] = NULL, tab);
}
