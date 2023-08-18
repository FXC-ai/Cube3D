/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:31:22 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:36:53 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	norm_chk_space(char *str, int *i)
{
	while (str[*i] && str[*i] != ',')
		(*i)++;
}

static void	norm_ini_sv(t_coord *color, int *start, int *i)
{
	(*color).x = -1;
	(*color).y = -1;
	(*color).z = -1;
	*start = 0;
	*i = 0;
}

t_coord	set_vector(char *str)
{
	int		i;
	int		start;
	char	*r;
	t_coord	color;

	norm_ini_sv(&color, &start, &i);
	norm_chk_space(str, &i);
	r = ft_substr(str, start, i);
	if (is_numeric(r) == 1)
		color.x = atoi(r);
	free(r);
	start = ++i;
	norm_chk_space(str, &i);
	r = ft_substr(str, start, i - start);
	if (is_numeric(r) == 1)
		color.y = atoi(r);
	free(r);
	start = ++i;
	norm_chk_space(str, &i);
	r = ft_substr(str, start, i - start);
	if (is_numeric(r) == 1)
		color.z = atoi(r);
	free(r);
	return (color);
}

int	check_coord_color(t_coord color)
{
	if (color.x < 0 || color.x > 255)
	{
		return (0);
	}
	if (color.y < 0 || color.y > 255)
	{
		return (0);
	}
	if (color.z < 0 || color.z > 255)
	{
		return (0);
	}
	return (1);
}

char	*get_floor_ceil(char **copy_of_file, char caract)
{
	int		i;
	int		ind_c;
	char	*str;

	i = 0;
	while (copy_of_file[i])
	{
		ind_c = 0;
		if (string_is_only_space(copy_of_file[i]) == 1)
			i++;
		else
		{
			while (is_space(copy_of_file[i][ind_c]) == 1)
				ind_c ++;
			if (copy_of_file[i][ind_c] == caract
			&& is_space(copy_of_file[i][ind_c + 1]))
			{
				str = go_to_next_and_get_arg(&copy_of_file[i][ind_c]);
				return (str);
			}
			i++;
		}
	}
	printf("Error : Floor color not found.\n");
	return (NULL);
}
