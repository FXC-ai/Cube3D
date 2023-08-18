/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:29:40 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:29:54 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_left(char **matrix, int lin, int col, t_coord size_matrix)
{
	(void) size_matrix;
	while (col >= 0)
	{
		if (matrix[lin][col] == '1')
		{
			return (1);
		}
		if (matrix[lin][col] == ' ')
		{
			return (0);
		}
		col--;
	}
	return (0);
}

int	onews(char c)
{
	return (c == '0'
		|| c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W');
}

static int	flood_fill(char **matrix, int lin, int col, t_coord size_matrix)
{
	if (onews(matrix[lin][col]) == 1)
	{
		if (check_right(matrix, lin, col, size_matrix) == 0)
		{
			return (0);
		}
		if (check_top(matrix, lin, col, size_matrix) == 0)
		{
			return (0);
		}
		if (check_bottom(matrix, lin, col, size_matrix) == 0)
		{
			return (0);
		}
		if (check_left(matrix, lin, col, size_matrix) == 0)
		{
			return (0);
		}
	}
	return (1);
}

int	wall_inspector(char **map_uncompleted, char **matrix, t_coord size_matrix)
{
	int	lin;
	int	col;

	lin = 1;
	while (lin < size_matrix.y - 1)
	{
		col = 0;
		while (col < size_matrix.x)
		{
			if (onews(matrix[lin][col]) == 1)
			{
				if (flood_fill(matrix, lin, col, size_matrix) == 0)
				{
					printf("Error : wall inspection issue.\n");
					ft_free_tabs(matrix);
					ft_free_tabs(map_uncompleted);
					return (0);
				}
			}
			col++;
		}
		lin++;
	}
	return (1);
}

int	check_player(char **matrix, char **map_uncompleted)
{
	int	lin;
	int	col;
	int	count;

	count = 0;
	lin = 0;
	while (matrix[lin] != NULL)
	{
		col = 0;
		while (matrix[lin][col] != '\0')
		{
			if (matrix[lin][col] == 'N' || matrix[lin][col] == 'S'
			|| matrix[lin][col] == 'E' || matrix[lin][col] == 'W')
				count++;
			col++;
		}
		lin++;
	}
	if (count == 1)
		return (1);
	ft_free_tabs(matrix);
	ft_free_tabs(map_uncompleted);
	printf("Error : Issue with player.\n");
	return (0);
}
