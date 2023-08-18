/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:09:52 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:09:56 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*get_filename(const char *file_path)
{
	char	*filename;
	int		i;
	int		filename_len;

	i = ft_strlen(file_path);
	filename_len = 0;
	while (i > 0 && file_path[i] != '/')
	{
		i--;
		filename_len ++;
	}
	if (file_path[i] == '/')
	{
		i++;
	}
	filename = ft_substr(file_path, i, filename_len);
	return (filename);
}

char	*get_extension(char *filename)
{
	int		filename_len;
	int		extension_len;
	int		i;

	filename_len = ft_strlen(filename);
	i = filename_len;
	extension_len = 0;
	while (filename[i] != '.' && i > 0)
	{
		i--;
		extension_len ++;
	}
	if (i == 0 || i == filename_len - 1)
	{
		return (NULL);
	}
	return (ft_substr(filename, filename_len - extension_len, extension_len));
}

int	filename_is_valid(const char *file_path)
{
	char	*extension;
	char	*filename;

	filename = get_filename(file_path);
	if (filename == NULL)
	{
		return (0);
	}
	extension = get_extension(filename);
	if (extension == NULL)
	{
		free (filename);
		return (0);
	}
	if (ft_strncmp(extension, ".cub", 5) != 0)
	{
		free(filename);
		free(extension);
		return (0);
	}
	free(filename);
	free(extension);
	return (1);
}

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	else
	{
		close (fd);
		return (1);
	}
}

int	arg_manager(char *file_path)
{
	char	*file_name;
	char	*extension;

	file_name = NULL;
	extension = NULL;
	if (filename_is_valid(file_path) == 0)
	{
		printf("Error : Invalid file.\n");
		return (0);
	}
	if (file_exists(file_path) == 0)
	{
		printf("Error : Impossible to open file : %s.\n", file_path);
		return (0);
	}
	return (1);
}
