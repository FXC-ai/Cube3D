/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:28:51 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:28:54 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_coord	get_player_position(t_coord coord_ini, int size_wall)
{
	t_coord	position;
	float	size_wall_f;

	size_wall_f = (float) size_wall;
	position.y = (int)(coord_ini.y * size_wall + size_wall_f * 0.5);
	position.x = (int)(coord_ini.x * size_wall + size_wall_f * 0.5);
	return (position);
}

int	init_map(t_map *map, char **copy, int end_parse_1)
{
	int		ind_map;
	int		h_map;
	char	**map_uncompleted;
	int		w_map;
	char	**matrix;

	ind_map = find_map(copy, end_parse_1);
	h_map = get_height_map(copy, ind_map);
	map_uncompleted = map_creator(copy, h_map, ind_map);
	if (map_uncompleted == NULL)
		return (0);
	w_map = get_width_map(map_uncompleted);
	matrix = matrix_creator(map_uncompleted, h_map, w_map);
	if (matrix == NULL)
		return (0);
	map->width_map = w_map * SIZE_WALL;
	map->height_map = h_map * SIZE_WALL;
	map->height_matrix = h_map;
	map->width_matrix = w_map;
	map->matrix = matrix;
	ft_free_tabs(map_uncompleted);
	return (1);
}
