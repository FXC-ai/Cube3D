/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:09:20 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:09:23 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	parse_the_map(char **copy_of_file, char **walls, char **ceil_floo)
{
	if (map_parser(copy_of_file, parser(copy_of_file)) == 0)
	{
		ft_free_tabs(copy_of_file);
		ft_free_tabs(walls);
		free(ceil_floo[1]);
		free(ceil_floo[0]);
		exit (0);
	}
}

void	free_general(t_general *general)
{
	ft_free_tabs(general->scene->map.matrix);
	free(general->sprites->wall_east);
	free(general->sprites->wall_north);
	free(general->sprites->wall_south);
	free(general->sprites->wall_west);
	free(general->sprites);
	free(general->keys);
	free(general->mlib);
	free(general->scene);
	free(general);
}

void	free_main(char **copy, char **w, char *ceil, char *floor)
{
	ft_free_tabs(copy);
	ft_free_tabs(w);
	free(ceil);
	free(floor);
}

int	main(int argc, char *argv[])
{
	char		**copy_of_file;
	char		**walls;
	char		*ceil_floo[2];
	t_coord		ceil_floov[2];
	t_general	*general;

	chk_file(argc, argv);
	copy_of_file = copy_file(argv[1]);
	parser(copy_of_file);
	walls = walls_manager(copy_of_file);
	if (walls == NULL)
		return (0);
	get_ceil_floo(copy_of_file, walls, ceil_floo);
	ceil_floov[1] = set_color_vec(copy_of_file, walls, ceil_floo, ceil_floo[1]);
	ceil_floov[0] = set_color_vec(copy_of_file, walls, ceil_floo, ceil_floo[0]);
	parse_the_map(copy_of_file, walls, ceil_floo);
	general = create_general(walls);
	if (general == NULL)
		return (0);
	if (feed_scene(general, copy_of_file, ceil_floov[1], ceil_floov[0]) == 1)
		init_window(general);
	free_main(copy_of_file, walls, ceil_floo[1], ceil_floo[0]);
	free_general(general);
	return (0);
}
