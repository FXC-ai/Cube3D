/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_manager3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:53:35 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:58:26 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*norm_get_no(char **walls, char **copy_of_file)
{
	char	*wall_no;

	wall_no = get_wall(copy_of_file, 'N', 'O');
	if (wall_no == NULL)
	{
		printf("Error : No Wall North.\n");
		ft_free_tabs(copy_of_file);
		free(walls);
		return (NULL);
	}
	return (wall_no);
}

char	*norm_get_so(char **walls, char **copy_of_file)
{
	char	*wall_so;

	wall_so = get_wall(copy_of_file, 'S', 'O');
	if (wall_so == NULL)
	{
		printf("Error : No Wall South.\n");
		ft_free_tabs(copy_of_file);
		ft_free_tabs(walls);
		return (NULL);
	}
	return (wall_so);
}

char	*norm_get_ea(char **walls, char **copy_of_file)
{
	char	*wall_ea;

	wall_ea = get_wall(copy_of_file, 'E', 'A');
	if (wall_ea == NULL)
	{
		printf("Error : No Wall East.\n");
		ft_free_tabs(copy_of_file);
		ft_free_tabs(walls);
		return (NULL);
	}
	return (wall_ea);
}

char	*norm_get_we(char **walls, char **copy_of_file)
{
	char	*wall_we;

	wall_we = get_wall(copy_of_file, 'W', 'E');
	if (wall_we == NULL)
	{
		printf("Error : No Wall West.\n");
		ft_free_tabs(copy_of_file);
		ft_free_tabs(walls);
		return (NULL);
	}
	return (wall_we);
}
