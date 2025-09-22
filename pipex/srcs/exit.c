/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:59:48 by althorel          #+#    #+#             */
/*   Updated: 2025/09/21 18:07:46 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	end_before_exit(t_data_child *child)
{
	if (child->fd != -1)
		close(child->fd);
	if (child->tab_cmd)
		ft_free_tab(child->tab_cmd);
	if (child->tab_path)
		ft_free_tab(child->tab_path);
	if (child->new_env)
		free(child->new_env);
	if (child->path)
		free(child->path);
}

void	ft_perror(const char *s, int error, t_data_child *child)
{
	if (child != NULL)
		end_before_exit(child);
	write(2, RED, 7);
	perror(s);
	write(2, END, 4);
	exit (error);
}
