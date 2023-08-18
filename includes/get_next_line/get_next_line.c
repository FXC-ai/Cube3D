/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:20:17 by fcoindre          #+#    #+#             */
/*   Updated: 2022/12/11 15:47:19 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	int		size_line;
	char	*line;
	int		i;

	size_line = 0;
	while (stash[size_line] != '\n' && stash[size_line] != '\0')
	{
		size_line ++;
	}
	line = (char *) malloc(sizeof(char) * (size_line + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < (size_line + 1))
	{
		line[i] = stash[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}

static char	*trim_stash(char *stash)
{
	size_t	size_line;
	size_t	size_stash;
	int		i;
	char	*tmp;
	size_t	montre;

	size_stash = 0;
	size_line = 0;
	while (stash[size_line] != '\n')
		size_line ++;
	size_stash = ft_strlen(stash);
	montre = size_stash - size_line;
	tmp = (char *) malloc(sizeof(char) * (montre));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (stash[i + size_line + 1] != '\0')
	{
		tmp[i] = stash[i + size_line + 1];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int	get_next_line_0(char **line, char **stash, char **tmp, char **buf)
{
	*tmp = ft_strjoin(*stash, *buf);
	free(*buf);
	free(*stash);
	*stash = ft_strdup(*tmp);
	free(*tmp);
	if (ft_strlen(*stash) > 0 && ft_strchr(*stash, '\n') != NULL)
	{
		*line = extract_line(*stash);
		*tmp = trim_stash(*stash);
		free(*stash);
		*stash = ft_strdup(*tmp);
		free(*tmp);
		return (1);
	}
	return (0);
}

static int	get_next_line_1(char **line, char **stash, char **tmp, char **buf)
{
	if (ft_strlen(*stash) > 0 && ft_strchr(*stash, '\n') != NULL)
	{
		*line = extract_line(*stash);
		*tmp = trim_stash(*stash);
		free(*stash);
		*stash = ft_strdup(*tmp);
		free(*tmp);
		if (*buf != NULL)
			free(*buf);
		return (1);
	}
	if (ft_strlen(*stash) > 0 && ft_strchr(*stash, '\n') == NULL)
	{
		*line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		if (*buf != NULL)
			free(*buf);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	int			chr_read;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chr_read = save_buffer(fd, &buf, &stash);
	while (chr_read > 0)
	{
		if (get_next_line_0(&line, &stash, &tmp, &buf) == 1)
			return (line);
		chr_read = save_buffer(fd, &buf, &stash);
	}
	if (get_next_line_1(&line, &stash, &tmp, &buf) == 1)
		return (line);
	if (ft_strlen(stash) == 0 && stash != NULL)
	{
		free(stash);
		stash = NULL;
	}
	if (buf != NULL)
		free(buf);
	return (NULL);
}
