/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:29:12 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 16:41:18 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	parse_first_wall(char *line, char **matrix, char **map_uncompleted)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (is_space(line[i]) == 1 || line[i] == '1')
		{
			is_valid = 1;
		}
		else
		{
			ft_free_tabs(matrix);
			ft_free_tabs(map_uncompleted);
			printf("Error : Inconsistent first or last wall.\n");
			return (0);
		}
		++i;
	}
	return (is_valid);
}

int	find_map(char **copy_file, int end_part_1)
{
	int	i;

	i = end_part_1 + 1;
	while (copy_file[i] != NULL)
	{
		if (string_is_only_space(copy_file[i]) == 0)
		{
			return (i);
		}
		i++;
	}
	printf("Error : map not found or misplace.\n");
	return (-1);
}

/* Renvoie le nombre de ligne depuis ind_map jusqu'a
la premiere ligne vide rencontrée */
int	get_height_map(char **copy_file, int ind_map)
{
	int	i;

	i = 0;
	while (copy_file[ind_map + i] != NULL
		&& string_is_only_space(copy_file[ind_map + i]) == 0)
	{
		i++;
	}
	if (i <= 2 || i > (HEIGHT / SCALE_MINI_MAP))
	{
		printf("Error : map incorrect.\n");
		return (0);
	}
	return (i);
}

int	check_eof(char **copy_file, int ind_map, int h_map)
{
	int	i;

	i = ind_map + h_map;
	while (copy_file[i] != NULL)
	{
		if (string_is_only_space(copy_file[i]) == 0)
		{
			printf("Error : EOF invalid.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/* Parcours les lignes du fichier depuis ind_map jusqu a ind_map + h_map */
/* Renvoie un tableau 2D de char contenant toutes les
 lignes lues entre ind_map et ind_map + h_map*/
char	**map_creator(char **copy_file, int h_map, int ind_map)
{
	char	**map;
	int		i;

	if (check_eof(copy_file, ind_map, h_map) == 0)
		return (NULL);
	map = (char **) malloc(sizeof(char *) * (h_map + 1));
	if (map == NULL)
	{
		printf("Error : uncompleted map (allocation error).\n");
		return (NULL);
	}
	i = 0;
	while (i < h_map)
	{
		map[i] = ft_strdup(copy_file[ind_map + i]);
		i++;
	}
	map[i] = NULL;
	if (check_caract_map(map) == 0)
		return (NULL);
	return (map);
}
