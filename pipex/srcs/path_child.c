/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:54:04 by althorel          #+#    #+#             */
/*   Updated: 2025/09/22 17:11:13 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path_in_path(t_data_child *child, int *stop)
{
	int		y;
	char	*path_tmp;

	y = 0;
	path_tmp = NULL;
	while (child->tab_path[y])
	{
		if (child->path)
			free(child->path);
		path_tmp = ft_strjoin(child->tab_path[y], "/");
		child->path = ft_strjoin(path_tmp, child->tab_cmd[0]);
		free(path_tmp);
		if (access(child->path, F_OK | X_OK) == 0)
		{
			*stop = 0;
			break ;
		}
		y++;
	}
}

void	find_path_in_env(char **env, t_data_child *child)
{
	int		stop;
	int		i;

	i = 0;
	stop = 1;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			child->new_env = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			child->tab_path = ft_split(child->new_env, ':');
			find_path_in_path(child, &stop);
			if (stop == 0)
				break ;
		}
			i++;
	}
	if (stop == 1)
	{
		ft_perror("path", 127, child);
	}
}

void	check_path(char *av2, char **env, t_data_child *child)
{
	if (av2 == NULL || av2[0] == '\0')
		ft_perror("missing cmd", 126, child);
	child->tab_cmd = ft_split(av2, ' ');
	if (!child->tab_cmd)
		ft_perror("split path", 1, child);
	if (ft_strncmp(child->tab_cmd[0], "/", 1) == 0)
	{
		if (access(child->tab_cmd[0], F_OK) == 0)
		{
			if (access(child->tab_cmd[0], X_OK) == -1)
				ft_perror("access path", 126, child);
			child->path = child->tab_cmd[0];
		}
		else
			ft_perror("access path", 127, child);
	}
	else
		find_path_in_env(env, child);
}
