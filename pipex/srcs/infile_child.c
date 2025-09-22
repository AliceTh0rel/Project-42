/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:57:01 by althorel          #+#    #+#             */
/*   Updated: 2025/09/21 18:11:07 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_infile(char *av1, t_data_child *child)
{
	if (access(av1, F_OK | R_OK) == -1)
		ft_perror("infile access", 1, child);
	child->fd = open(av1, O_RDONLY);
	if (child->fd == -1)
		ft_perror("outfile open", 1, child);
	if (dup2(child->fd, STDIN_FILENO) == -1)
		ft_perror("infile dup2", 1, child);
	if (child->fd != -1)
		close(child->fd);
}

void	check_outfile(char *av1, t_data_child *child)
{
	child->fd = open(av1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (child->fd == -1)
		ft_perror("outfile open", 1, child);
	if (dup2(child->fd, STDOUT_FILENO) == -1)
		ft_perror("outfile dup2", 1, child);
	if (child->fd != -1)
		close(child->fd);
}
