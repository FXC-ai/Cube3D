/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:50:44 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 16:13:30 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	draw_grid(t_general *general)
{
	t_mlib	*mlib;
	int		i;
	int		j;

	mlib = general->mlib;
	i = 0;
	while (i < general->scene->map.width_matrix * SCALE_MINI_MAP)
	{
		j = 0;
		while (j < general->scene->map.height_matrix * SCALE_MINI_MAP)
		{
			if (i % SCALE_MINI_MAP == 0)
			{
				my_mlx_pixel_put(&mlib->data, i, j, 0x00AA00);
			}
			if (j % SCALE_MINI_MAP == 0)
			{
				my_mlx_pixel_put(&mlib->data, i, j, 0x00AA00);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_general *general)
{
	t_mlib	*mlib;
	int		size;
	int		x;
	int		y;
	int		i;

	mlib = general->mlib;
	x = general->scene->player.pos2d.x;
	y = general->scene->player.pos2d.y;
	size = 3;
	i = -size;
	while (i <= size)
	{
		my_mlx_pixel_put(&mlib->data, x + i, y, 0x00FF00);
		my_mlx_pixel_put(&mlib->data, x, y + i, 0x00FF00);
		i++;
	}
}

void	draw_arrow(t_general *general, t_coord start_arrow, t_vec dir)
{
	int		color;
	t_coord	end_arrow;

	color = 0xFF0000;
	start_arrow = convertcoord2d(start_arrow);
	end_arrow.x = start_arrow.x + 8 * dir.x;
	end_arrow.y = start_arrow.y + 8 * dir.y;
	my_mlx_pixel_put(&general->mlib->data, end_arrow.x, end_arrow.y, color);
}

int	render_mini_map(t_general *general)
{
	t_mlib	*mlib;

	mlib = general->mlib;
	mlib->data.img_ptr = mlx_new_image(mlib->utils.mlx, WIDTH, HEIGHT);
	mlib->data.addr = mlx_get_data_addr(mlib->data.img_ptr,
			&mlib->data.bits_per_pixel,
			&mlib->data.line_length,
			&mlib->data.endian);
	render_wall2d(general);
	move(general);
	draw_player(general);
	draw_arrow(general, general->scene->player.pos, general->scene->player.dir);
	mlx_put_image_to_window(mlib->utils.mlx,
		mlib->utils.win,
		mlib->data.img_ptr, 0, 0);
	mlx_destroy_image(mlib->utils.mlx, mlib->data.img_ptr);
	return (0);
}
