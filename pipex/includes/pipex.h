/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:02:07 by althorel          #+#    #+#             */
/*   Updated: 2025/09/22 12:48:30 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <wait.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

typedef struct s_data_child
{
	char	*path;
	char	**tab_cmd;
	char	**tab_path;
	char	*new_env;
	int		fd;
}	t_data_child;

//routine_child
void	find_path_in_path(t_data_child *child, int *stop);
void	check_path(char *av2, char **env, t_data_child *child);
void	find_path_in_env(char **env, t_data_child *child);
void	init_data_child(t_data_child *child);
void	routine_first_child(char *av1, char *av2, char **env, int pipe_fd[2]);
void	check_infile(char *av1, t_data_child *child);
void	routine_second_child(char *av3, char *av4, char **env, int pipe_fd[2]);
void	check_outfile(char *av1, t_data_child *child);

//exit
void	ft_perror(const char *s, int error, t_data_child *child);
void	ft_free_tab(char **tab);
void	end_before_exit(t_data_child *child);

#endif