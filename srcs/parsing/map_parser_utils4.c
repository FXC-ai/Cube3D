/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:29:21 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:30:09 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_caract_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1'
			&& line[i] != '0'
			&& line[i] != 'N'
			&& line[i] != 'W'
			&& line[i] != 'E'
			&& line[i] != 'S'
			&& line[i] != ' '
			&& line[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_caract_map(char **map_unc)
{
	int	i;

	i = 0;
	while (map_unc[i] != NULL)
	{
		if (check_caract_line(map_unc[i]) == 0)
		{
			ft_free_tabs(map_unc);
			printf("Error : inconsistent character in map.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	*line_matrix_creator(char *line, int w_matrix)
{
	char	*copy_line;
	int		i;

	copy_line = (char *) malloc(sizeof(char) * (w_matrix + 1));
	if (copy_line == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0' && i < w_matrix)
	{
		copy_line[i] = line [i];
		i++;
	}
	while (i < w_matrix)
	{
		copy_line[i] = ' ';
		i++;
	}
	copy_line[i] = '\0';
	return (copy_line);
}

char	**matrix_creator(char **map_unc, int h_matrix, int w_matrix)
{
	int		i;
	char	**matrix;

	matrix = (char **) malloc(sizeof(char *) * (h_matrix + 1));
	if (matrix == NULL)
	{
		ft_free_tabs(matrix);
		ft_free_tabs(map_unc);
		printf("Error : issue with matrix allocation.\n");
		return (NULL);
	}
	i = 0;
	while (map_unc[i] != NULL)
	{
		matrix[i] = line_matrix_creator(map_unc[i], w_matrix);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

int	check_first_one(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]) == 1 && line[i] != '\0')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}
