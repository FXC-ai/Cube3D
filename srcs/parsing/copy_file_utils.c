/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:10:17 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:10:30 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

/* Renvoie le nombre de ligne du fichier a parser */
int	get_size_file(char *filename)
{
	int		fd;
	char	*line;
	int		size_file;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	size_file = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		size_file++;
	}
	close(fd);
	if (line)
		free(line);
	return (size_file);
}

static	int	get_fd(char *filename, char **copy)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error : Error with configuration file.\n");
		free(copy);
		exit (0);
	}
	return (fd);
}

/* Copie le fichier a parser dans un tableau 2D de char */
char	**copy_file(char *filename)
{
	int		fd;
	char	*line;
	char	**copy;
	int		i;
	int		size_file;

	line = NULL;
	size_file = get_size_file(filename);
	copy = (char **) malloc(sizeof(char *) * (size_file + 1));
	if (copy == NULL)
		exit (0);
	fd = get_fd(filename, copy);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		copy[i] = line;
		line = get_next_line(fd);
		i++;
	}
	copy[i] = NULL;
	close(fd);
	if (line)
		free(line);
	return (copy);
}
