/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:48:52 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:56:35 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	norm_init_walls(char **walls)
{
	walls[0] = NULL;
	walls[1] = NULL;
	walls[2] = NULL;
	walls[3] = NULL;
	walls[4] = NULL;
}

static void	norm_free_wm(char **copy_of_file, char **walls)
{
	ft_free_tabs(copy_of_file);
	ft_free_tabs(walls);
}

char	**walls_manager(char **copy_of_file)
{
	char	**walls;

	walls = (char **) ft_calloc(5, sizeof(char *));
	if (walls == NULL)
		return (NULL);
	norm_init_walls(walls);
	walls[0] = norm_get_no(walls, copy_of_file);
	if (walls[0] == NULL)
		return (NULL);
	walls[1] = norm_get_so(walls, copy_of_file);
	if (walls[0] == NULL)
		return (NULL);
	walls[2] = norm_get_ea(walls, copy_of_file);
	if (walls[0] == NULL)
		return (NULL);
	walls[3] = norm_get_we(walls, copy_of_file);
	if (walls[0] == NULL)
		return (NULL);
	if (walls_manager_exists(walls) == 0)
	{
		norm_free_wm(copy_of_file, walls);
		printf("Error : Issue with wall file.\n");
		return (NULL);
	}
	return (walls);
}
