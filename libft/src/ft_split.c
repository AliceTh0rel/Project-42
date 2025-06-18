/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:32:20 by althorel          #+#    #+#             */
/*   Updated: 2025/05/06 18:48:12 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	nb;

	nb = 0;
	while (*s)
	{
		if (*s != c)
		{
			nb++;
			while (*s && *s != c)
			s++;
		}
		else
			s++;
	}
	return (nb);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	char const	*start;
	int			len;
	int			nb;
	int			j;

	nb = count_word(s, c);
	tab = malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	j = 0;
	while (*s && j < nb)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		len = s - start;
		tab[j] = ft_substr(start, 0, len);
		if (!tab[j])
			return (ft_free(tab), NULL);
		j++;
	}
	return (tab[j] = NULL, tab);
}
/*
int main ()
{
	int	i;
	
	i = 0;
	while (i < count_word("cha lu les am is ?", ' '))
	{
		printf("%s\n", ft_split("cha lu les am is ?", ' ')[i]);
		i++;
	}
}
*/
