/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:51:15 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 11:53:06 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	draw_wall(t_general *general, t_coord coord_wall)
{
	int		x;
	int		y;
	t_mlib	*mlib;

	mlib = general->mlib;
	y = 0;
	while (y < SCALE_MINI_MAP)
	{
		x = 0;
		while (x < SCALE_MINI_MAP)
		{
			my_mlx_pixel_put(&mlib->data, coord_wall.x * SCALE_MINI_MAP + x,
				coord_wall.y * SCALE_MINI_MAP + y,
				0x1100FF);
			x++;
		}
		y++;
	}
}

void	render_wall2d(t_general *general)
{
	t_coord	coord_wall;
	int		i;
	int		j;

	j = 0;
	while (j < general->scene->map.height_matrix)
	{
		i = 0;
		while (i < general->scene->map.width_matrix)
		{
			if (general->scene->map.matrix[j][i] == '1')
			{
				coord_wall.x = i;
				coord_wall.y = j;
				draw_wall(general, coord_wall);
			}
			i++;
		}
		j++;
	}
}
