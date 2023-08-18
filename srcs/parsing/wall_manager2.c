/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_manager2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:48:45 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:51:22 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*get_wall(char **copy_of_file, char first, char second)
{
	int	i;
	int	ind_c;

	i = 0;
	while (copy_of_file[i])
	{
		ind_c = 0;
		if (string_is_only_space(copy_of_file[i]) == 1)
		{
			i++;
		}
		else
		{
			while (is_space(copy_of_file[i][ind_c]) == 1)
				ind_c ++;
			if (copy_of_file[i][ind_c] == first
			&& copy_of_file[i][ind_c + 1] == second
			&& is_space(copy_of_file[i][ind_c + 2]))
			{
				return (go_to_next_and_get_arg(&copy_of_file[i][ind_c]));
			}
			i++;
		}
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static int	check_points(char *filename)
{
	if (ft_strcmp(filename, ".") == 0)
		return (0);
	if (ft_strcmp(filename, "..") == 0)
		return (0);
	return (1);
}

int	walls_manager_exists(char **walls)
{
	int	i;

	i = 0;
	while (walls[i] != NULL)
	{
		if (check_points (walls[i]) == 0)
			return (0);
		if (file_exists(walls[i]) == 0)
		{
			printf("Error : Impossible to open (%s)\n", walls[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
