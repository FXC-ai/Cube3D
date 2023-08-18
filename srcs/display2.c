/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:02:20 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 16:13:30 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_map(t_map map)
{
	printf("----MAP----\n");
	print_tab(map.matrix);
	printf("   height_map = %d\n", map.height_map);
	printf("    width_map = %d\n", map.width_map);
	printf("heigth_matrix = %d\n", map.height_matrix);
	printf(" width_matrix = %d\n", map.width_matrix);
	printf("    size_wall = %d\n", SIZE_WALL);
	printf("\n");
}

void	print_player(t_player player)
{
	printf("----PLAYER----\n");
	print_coord(player.coord_ini);
	printf("pos : ");
	print_coord(player.pos);
	printf("pos2d : \n");
	print_coord(player.pos2d);
	printf("dir : ");
	print_vec(player.dir);
	printf("speed = %f\n", player.speed);
	printf("\n");
}

void	print_sprites(t_sprites *sprites)
{
	printf("----TEXTURES SPRITES----\n");
	printf("NORTH :\n");
	print_sprite(sprites->wall_north);
	printf("SOUTH :\n");
	print_sprite(sprites->wall_south);
	printf("EAST  :\n");
	print_sprite(sprites->wall_east);
	printf("WEST  :\n");
	print_sprite(sprites->wall_west);
	printf("\n");
}

void	print_scene(t_scene *scene)
{
	printf("----SCENE----\n");
	printf("button minimap = %d\n", scene->mini_map);
	printf("    ceil_color = %X\n", scene->sky_color);
	printf("   floor_color = %X\n", scene->floor_color);
	printf("\n");
	print_map(scene->map);
	print_player(scene->player);
}
