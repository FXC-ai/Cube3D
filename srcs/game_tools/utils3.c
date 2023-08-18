/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:46:49 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 11:46:51 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static	int	load_no(t_general *general, t_sprites *sprites)
{
	void	*temp;

	temp = mlx_png_file_to_image(general->mlib->utils.mlx,
			general->sprites->wall_north->path,
			&sprites->wall_north->sprite_w,
			&sprites->wall_north->sprite_h);
	if (temp == NULL)
		return (0);
	sprites->wall_north->data_spr.img_ptr = temp;
	sprites->wall_north->data_spr.addr = mlx_get_data_addr(
			sprites->wall_north->data_spr.img_ptr,
			&sprites->wall_north->data_spr.bits_per_pixel,
			&sprites->wall_north->data_spr.line_length,
			&sprites->wall_north->data_spr.endian);
	return (1);
}

static	int	load_so(t_general *general, t_sprites *sprites)
{
	void	*temp;

	temp = mlx_png_file_to_image(general->mlib->utils.mlx,
			general->sprites->wall_south->path,
			&sprites->wall_south->sprite_w,
			&sprites->wall_south->sprite_h);
	if (temp == NULL)
		return (0);
	sprites->wall_south->data_spr.img_ptr = temp;
	sprites->wall_south->data_spr.addr = mlx_get_data_addr(
			sprites->wall_south->data_spr.img_ptr,
			&sprites->wall_south->data_spr.bits_per_pixel,
			&sprites->wall_south->data_spr.line_length,
			&sprites->wall_south->data_spr.endian);
	return (1);
}

static	int	load_ea(t_general *general, t_sprites *sprites)
{
	void	*temp;

	temp = mlx_png_file_to_image(general->mlib->utils.mlx,
			general->sprites->wall_east->path,
			&sprites->wall_east->sprite_w,
			&sprites->wall_east->sprite_h);
	if (temp == NULL)
		return (0);
	sprites->wall_east->data_spr.img_ptr = temp;
	sprites->wall_east->data_spr.addr = mlx_get_data_addr(
			sprites->wall_east->data_spr.img_ptr,
			&sprites->wall_east->data_spr.bits_per_pixel,
			&sprites->wall_east->data_spr.line_length,
			&sprites->wall_east->data_spr.endian);
	return (1);
}

static	int	load_we(t_general *general, t_sprites *sprites)
{
	void	*temp;

	temp = mlx_png_file_to_image(general->mlib->utils.mlx,
			general->sprites->wall_west->path,
			&sprites->wall_west->sprite_w,
			&sprites->wall_west->sprite_h);
	if (temp == NULL)
		return (0);
	sprites->wall_west->data_spr.img_ptr = temp;
	sprites->wall_west->data_spr.addr = mlx_get_data_addr(
			sprites->wall_west->data_spr.img_ptr,
			&sprites->wall_west->data_spr.bits_per_pixel,
			&sprites->wall_west->data_spr.line_length,
			&sprites->wall_west->data_spr.endian);
	return (1);
}

int	load_texture_png(t_general *general)
{
	t_sprites	*sprites;

	sprites = general->sprites;
	if (load_no(general, sprites) == 0)
		return (0);
	if (load_so(general, sprites) == 0)
		return (0);
	if (load_ea(general, sprites) == 0)
		return (0);
	if (load_we(general, sprites) == 0)
		return (0);
	return (1);
}
