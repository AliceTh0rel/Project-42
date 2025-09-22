/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:21:22 by althorel          #+#    #+#             */
/*   Updated: 2025/09/21 18:11:01 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data_child(t_data_child *child)
{
	child->path = NULL;
	child->tab_cmd = NULL;
	child->tab_path = NULL;
	child->new_env = NULL;
	child->fd = -1;
}

void	routine_first_child(char *av1, char *av2, char **env, int pipe_fd[2])
{
	t_data_child	child;

	close(pipe_fd[0]);
	init_data_child(&child);
	check_infile(av1, &child);
	check_path(av2, env, &child);
	child.fd = pipe_fd[1];
	if (dup2(child.fd, STDOUT_FILENO) == -1)
		ft_perror("dup2", 1, &child);
	if (child.fd != -1)
		close(child.fd);
	if (execve(child.path, child.tab_cmd, env) == -1)
		ft_perror("execve", 1, &child);
	end_before_exit(&child);
}

void	routine_second_child(char *av3, char *av4, char **env, int pipe_fd[2])
{
	t_data_child	child;

	close(pipe_fd[1]);
	init_data_child(&child);
	check_outfile(av4, &child);
	check_path(av3, env, &child);
	child.fd = pipe_fd[0];
	if (dup2(child.fd, STDIN_FILENO) == -1)
		ft_perror("dup2", 1, &child);
	if (child.fd != -1)
		close(child.fd);
	if (execve(child.path, child.tab_cmd, env) == -1)
		ft_perror("execve", 1, &child);
	end_before_exit(&child);
}
