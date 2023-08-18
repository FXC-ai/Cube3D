/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:11:09 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:11:12 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static t_coord	coor_size(int h_matrix, int w_matrix)
{
	t_coord	size_matrix;

	size_matrix.x = w_matrix;
	size_matrix.y = h_matrix;
	return (size_matrix);
}

static int	check_matrix(char **matrix, char **map_unc, int h_map, int w_map)
{
	if (parse_first_wall(matrix[0], matrix, map_unc) == 0)
		return (0);
	if (check_last_first_one(matrix, map_unc) == 0)
		return (0);
	if (parse_first_wall(matrix[h_map - 1], matrix, map_unc) == 0)
		return (0);
	if (check_player(matrix, map_unc) == 0)
		return (0);
	if (wall_inspector(map_unc, matrix, coor_size(h_map, w_map)) == 0)
		return (0);
	return (1);
}

static void	free_map_matrix(char **map_unc, char **matrix)
{
	ft_free_tabs(map_unc);
	ft_free_tabs(matrix);
}

int	map_parser(char **copy, int end_parse_1)
{
	int		ind_map;
	int		h_map;
	char	**map_uncompleted;
	int		w_map;
	char	**matrix;

	ind_map = find_map(copy, end_parse_1);
	if (ind_map == -1)
		return (0);
	h_map = get_height_map(copy, ind_map);
	if (h_map == 0)
		return (0);
	map_uncompleted = map_creator(copy, h_map, ind_map);
	if (map_uncompleted == NULL)
		return (0);
	w_map = get_width_map(map_uncompleted);
	if (w_map == 0)
		return (0);
	matrix = matrix_creator(map_uncompleted, h_map, w_map);
	if (matrix == NULL)
		return (0);
	if (check_matrix(matrix, map_uncompleted, h_map, w_map) == 0)
		return (0);
	free_map_matrix(map_uncompleted, matrix);
	return (1);
}
