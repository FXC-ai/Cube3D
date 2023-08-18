/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:29:34 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:29:59 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	get_letter_oreintation(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == 'N' || matrix[i][j] == 'S'
			|| matrix[i][j] == 'E' || matrix[i][j] == 'W')
				return (matrix[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

t_coord	get_player_coord(char **matrix)
{
	int		lin;
	int		col;
	t_coord	coord_ini;

	coord_ini.x = -1;
	coord_ini.y = -1;
	coord_ini.z = 0;
	lin = 0;
	while (matrix[lin] != NULL)
	{
		col = 0;
		while (matrix[lin][col] != '\0')
		{
			if (matrix[lin][col] == 'N' || matrix[lin][col] == 'S'
			|| matrix[lin][col] == 'E' || matrix[lin][col] == 'W')
			{
				coord_ini.y = lin * SIZE_WALL + SIZE_WALL / 2;
				coord_ini.x = col * SIZE_WALL + SIZE_WALL / 2;
				return (coord_ini);
			}
			col++;
		}
		lin++;
	}
	return (coord_ini);
}

static	void	norm_init_vec(t_vec *orientation_ini, float xf, float yf)
{
	(*orientation_ini).x = xf;
	(*orientation_ini).y = yf;
	(*orientation_ini).z = 0;
}

t_vec	get_player_orient(char **matrix)
{
	char	orientation;
	t_vec	orientation_ini;

	norm_init_vec(&orientation_ini, -1, -1);
	orientation = get_letter_oreintation(matrix);
	if (orientation == 'N')
	{
		norm_init_vec(&orientation_ini, 0, -1);
	}
	else if (orientation == 'S')
	{
		norm_init_vec(&orientation_ini, 0, 1);
	}
	else if (orientation == 'W')
	{
		norm_init_vec(&orientation_ini, -1, 0);
	}
	else if (orientation == 'E')
	{
		norm_init_vec(&orientation_ini, 1, 0);
	}
	return (orientation_ini);
}

int	get_size_wall(int map_w, int map_h)
{
	int	size_wall;
	int	rap_h;
	int	rap_w;

	rap_h = HEIGHT / map_h;
	rap_w = WIDTH / map_w;
	if (rap_h < rap_w)
	{
		size_wall = (HEIGHT - 1) / map_h;
	}
	else
	{
		size_wall = (WIDTH - 1) / map_w;
	}
	return (size_wall);
}
