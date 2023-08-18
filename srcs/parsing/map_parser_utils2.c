/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:29:04 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:30:17 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	void	norm_init(int *size_current_line, int *max_size, int *i, int *j)
{
	*i = 0;
	*j = 0;
	*max_size = 0;
	*size_current_line = 0;
}

static void	norm_loop(int *size_current_line, int *j)
{
	(*j)++;
	(*size_current_line)++;
}

static	int	norm_free(char **map, int max_size)
{
	if (max_size < 3 || max_size > (WIDTH / SCALE_MINI_MAP))
	{
		ft_free_tabs(map);
		printf("Error : width map incorrect.\n");
		return (0);
	}
	return (1);
}

int	get_width_map(char **map)
{
	int	size_current_line;
	int	max_size;
	int	i;
	int	j;

	norm_init(&size_current_line, &max_size, &i, &j);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ')
			norm_loop(&size_current_line, &j);
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '1' || onews(map[i][j]) == 1 || map[i][j] == ' ')
				size_current_line++;
			j++;
		}
		if (size_current_line > max_size)
			max_size = size_current_line;
		size_current_line = 0;
		i++;
	}
	if (norm_free(map, max_size) == 0)
		return (0);
	return (max_size);
}
