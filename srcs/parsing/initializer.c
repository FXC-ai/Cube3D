/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:10:50 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:10:54 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_mlib	*init_mlib(t_general *general)
{
	t_mlib	*mlib;

	mlib = (t_mlib *) malloc(sizeof(t_mlib));
	if (mlib == NULL)
	{
		free (general->scene);
		free (general);
		return (NULL);
	}
	mlib->utils.mlx = mlx_init();
	return (mlib);
}

t_keys	*init_key(t_general *general)
{
	t_keys	*keys;

	keys = (t_keys *) malloc(sizeof(t_keys));
	if (keys == NULL)
	{
		free(general->mlib);
		free (general->scene);
		free (general);
		return (NULL);
	}
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->arrow_l = 0;
	keys->arrow_r = 0;
	return (keys);
}

t_sprite	*init_sprite(char *path)
{
	t_sprite	*wall;

	wall = (t_sprite *) malloc(sizeof(t_sprite));
	if (wall == NULL)
	{
		return (NULL);
	}
	wall->path = path;
	return (wall);
}

t_sprites	*init_sprites(char **walls, t_general *general)
{
	t_sprites	*sprites;

	sprites = (t_sprites *) malloc(sizeof(t_sprites));
	if (sprites == NULL)
	{
		free(general->keys);
		free(general->mlib);
		free (general->scene);
		free (general);
		return (NULL);
	}
	sprites->wall_east = init_sprite(walls[2]);
	sprites->wall_west = init_sprite(walls[3]);
	sprites->wall_south = init_sprite(walls[1]);
	sprites->wall_north = init_sprite(walls[0]);
	return (sprites);
}
