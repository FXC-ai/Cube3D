/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:29:28 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:30:04 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_last_one(char *line)
{
	int	i;

	i = ft_strlen(line);
	i--;
	while (is_space(line[i]) == 1 && i >= 0)
	{
		i--;
	}
	if (line[i] == '1')
		return (1);
	return (0);
}

int	check_last_first_one(char **matrix, char **map_uncompleted)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (check_first_one(matrix[i]) == 0 || check_last_one(matrix[i]) == 0)
		{
			ft_free_tabs(matrix);
			ft_free_tabs(map_uncompleted);
			printf("Error : Inconsistent wall.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_right(char **matrix, int lin, int col, t_coord size_matrix)
{
	int	i;

	(void) size_matrix;
	i = 0;
	while (matrix[lin][col + i] != '\0')
	{
		if (matrix[lin][col + i] == '1')
		{
			return (1);
		}
		if (matrix[lin][col + i] == ' ')
		{
			return (0);
		}
		i++;
	}
	return (0);
}

int	check_top(char **matrix, int lin, int col, t_coord size_matrix)
{
	(void) size_matrix;
	while (lin >= 0)
	{
		if (matrix[lin][col] == '1')
		{
			return (1);
		}
		if (matrix[lin][col] == ' ')
		{
			return (0);
		}
		lin--;
	}
	return (0);
}

int	check_bottom(char **matrix, int lin, int col, t_coord size_matrix)
{
	while (lin < size_matrix.y)
	{
		if (matrix[lin][col] == '1')
		{
			return (1);
		}
		if (matrix[lin][col] == ' ')
		{
			return (0);
		}
		lin++;
	}
	return (0);
}
