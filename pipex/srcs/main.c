/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:06:08 by althorel          #+#    #+#             */
/*   Updated: 2025/09/22 12:24:20 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	end(int pipe_fd[2], pid_t pid1, pid_t pid2, int status)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		ft_perror("Expected 4 arguments : infile cmd1 cmd2 outfile", 1, NULL);
	if (pipe(pipe_fd) == -1)
		ft_perror("pipe", 1, NULL);
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("fork", 1, NULL);
	if (pid1 == 0)
		routine_first_child(av[1], av[2], env, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("fork", 1, NULL);
	if (pid2 == 0)
		routine_second_child(av[3], av[4], env, pipe_fd);
	status = end(pipe_fd, pid1, pid2, 0);
	return (status);
}
