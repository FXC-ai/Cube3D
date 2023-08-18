/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:06:55 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 16:13:30 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_general	*create_general(char **walls)
{
	t_general	*general;

	general = (t_general *) malloc (sizeof(t_general));
	if (general == NULL)
		return (NULL);
	general->scene = malloc(sizeof(t_scene));
	if (general->scene == NULL)
	{
		free(general);
		return (NULL);
	}
	general->mlib = init_mlib(general);
	if (general->mlib == NULL)
		return (NULL);
	general->keys = init_key(general);
	if (general->keys == NULL)
		return (NULL);
	general->sprites = init_sprites(walls, general);
	if (general->sprites == NULL)
		return (NULL);
	return (general);
}

int	feed_scene(t_general *general, char **copy, t_coord floor, t_coord ceil)
{
	int	end;

	end = parser(copy);
	if (init_map(&general->scene->map, copy, end) == 0)
	{
		printf("Error init_map\n");
		return (0);
	}
	general->scene->floor_color = create_trgb(0, floor.x, floor.y, floor.z);
	general->scene->sky_color = create_trgb(0, ceil.x, ceil.y, ceil.z);
	general->scene->player.pos = get_player_coord(general->scene->map.matrix);
	general->scene->player.coord_ini = general->scene->player.pos;
	general->scene->player.pos2d = convertcoord2d(general->scene->player.pos);
	general->scene->player.dir = get_player_orient(general->scene->map.matrix);
	general->scene->player.speed = 0.1f * SIZE_WALL;
	general->scene->mini_map = 0;
	if (load_texture_png(general) == 0)
	{
		printf("Error : Imposible to load textures\n");
		return (0);
	}
	return (1);
}

void	chk_file(int argc, char *argv[])
{
	int	size_file;

	if (argc != 2)
	{
		printf("Error : Invalid number of arguments.\n");
		exit (0);
	}
	if (arg_manager(argv[1]) == 0)
		exit (0);
	size_file = get_size_file(argv[1]);
	if (size_file <= 0)
	{
		printf("Error : File is empty or not a text file.\n");
		exit (0);
	}
}

void	get_ceil_floo(char **copy, char **walls, char **ceil_floo)
{
	ceil_floo[1] = get_floor_ceil(copy, 'F');
	if (ceil_floo[1] == NULL)
	{
		ft_free_tabs(copy);
		ft_free_tabs(walls);
		exit (0);
	}
	ceil_floo[0] = get_floor_ceil(copy, 'C');
	if (ceil_floo[0] == NULL)
	{
		ft_free_tabs(copy);
		ft_free_tabs(walls);
		free(ceil_floo[1]);
		printf("Error : Invalid ceil color.\n");
		exit (0);
	}
}

t_coord	set_color_vec(char **copy, char **w, char **clrs, char *clr)
{
	t_coord	color_vec;

	color_vec = set_vector(clr);
	if (check_coord_color(color_vec) == 0)
	{
		ft_free_tabs(copy);
		ft_free_tabs(w);
		free(clrs[1]);
		free(clrs[0]);
		printf ("Error : Invalid color.\n");
		exit (0);
	}
	return (color_vec);
}
