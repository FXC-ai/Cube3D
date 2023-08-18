/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:20 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 16:03:21 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render3D.h"

int	get_color_wall_north(t_general *general, int x, int h_wall, int max_wall_h)
{
	t_sprites		*sprites;
	char			*pixel;
	unsigned int	color;
	int				x_pix;
	int				y_pix;

	sprites = general->sprites;
	x_pix = (x % SIZE_WALL) * sprites->wall_north->sprite_w / SIZE_WALL;
	y_pix = (h_wall * general->sprites->wall_north->sprite_h / max_wall_h)
		% sprites->wall_north->sprite_h;
	pixel = sprites->wall_north->data_spr.addr
		+ (y_pix * sprites->wall_north->data_spr.line_length + x_pix
			* (sprites->wall_north->data_spr.bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

int	get_color_wall_south(t_general *general, int x, int h_wall, int max_wall_h)
{
	t_sprites		*sprites;
	char			*pixel;
	unsigned int	color;
	int				x_pix;
	int				y_pix;

	sprites = general->sprites;
	x_pix = (x % SIZE_WALL) * sprites->wall_south->sprite_w / SIZE_WALL;
	y_pix = (h_wall * general->sprites->wall_south->sprite_h / max_wall_h)
		% sprites->wall_south->sprite_h;
	pixel = sprites->wall_south->data_spr.addr
		+ (y_pix * sprites->wall_south->data_spr.line_length + x_pix
			* (sprites->wall_south->data_spr.bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

int	get_color_wall_east(t_general *general, int x, int h_wall, int max_wall_h)
{
	t_sprites		*sprites;
	char			*pixel;
	unsigned int	color;
	int				x_pix;
	int				y_pix;

	sprites = general->sprites;
	x_pix = (x % SIZE_WALL) * sprites->wall_east->sprite_w / SIZE_WALL;
	y_pix = (h_wall * general->sprites->wall_east->sprite_h / max_wall_h)
		% sprites->wall_east->sprite_h;
	pixel = sprites->wall_east->data_spr.addr
		+ y_pix * sprites->wall_east->data_spr.line_length + x_pix
		* (sprites->wall_east->data_spr.bits_per_pixel / 8);
	color = *(unsigned int *)pixel;
	return (color);
}

int	get_color_wall_west(t_general *general, int x, int h_wall, int max_wall_h)
{
	t_sprites		*sprites;
	char			*pixel;
	unsigned int	color;
	int				x_pix;
	int				y_pix;

	sprites = general->sprites;
	x_pix = (x % SIZE_WALL) * sprites->wall_west->sprite_w / SIZE_WALL;
	y_pix = (h_wall * general->sprites->wall_west->sprite_h / max_wall_h)
		% sprites->wall_west->sprite_h;
	pixel = sprites->wall_west->data_spr.addr
		+ y_pix * sprites->wall_west->data_spr.line_length + x_pix
		* (sprites->wall_west->data_spr.bits_per_pixel / 8);
	color = *(unsigned int *)pixel;
	return (color);
}
