/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:45:06 by althorel          #+#    #+#             */
/*   Updated: 2025/06/05 16:13:25 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_stash(char *stash, char *buff)
{
	char	*temp;

	temp = NULL;
	if (stash)
	{
		temp = ft_strdup(stash);
		free(stash);
		stash = ft_strjoin(temp, buff);
		free(temp);
	}
	else
		stash = ft_strdup(buff);
	return (stash);
}

void	*ft_reset(char **stash, char **buff)
{
	free(*buff);
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*ft_write(char **ptr_stash, ssize_t read_byte)
{
	char	*line;
	char	*new_line;
	char	*temp;

	if (!ptr_stash || !*ptr_stash)
		return (NULL);
	new_line = ft_strchr(*ptr_stash, '\n');
	if (!new_line)
		new_line = ft_strchr(*ptr_stash, '\0');
	line = NULL;
	if (!new_line || read_byte == 0)
	{
		line = ft_strdup(*ptr_stash);
		free(*ptr_stash);
		*ptr_stash = NULL;
		if (!line || line[0] == 0)
			return (free(line), NULL);
		return (line);
	}
	line = ft_substr(*ptr_stash, 0, new_line - *ptr_stash + 1);
	temp = ft_strdup(new_line + 1);
	free(*ptr_stash);
	*ptr_stash = NULL;
	*ptr_stash = temp;
	return (line);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	ssize_t		read_byte;

	read_byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (read_byte > 0)
	{
		if (stash && ft_check(stash) == 1)
			break ;
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
			return (ft_reset(&stash, &buff));
		buff[read_byte] = '\0';
		stash = ft_join_stash(stash, buff);
	}
	free(buff);
	buff = NULL;
	return (ft_write(&stash, read_byte));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	fd = open("file.txt", O_RDONLY);
// 	if (fd < 0)
// 	return (1);
// 	int i = 0;
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 		break;
// 		printf("testend%d:'%s'",i++, str);
// 		free(str);
// 	}
// 	return (0);
// }
