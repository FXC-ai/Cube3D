/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:49:00 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:54:27 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	get_dist(t_coord pos, t_coord ray, float delta_angle)
{
	float	dist;

	dist = sqrtf((ray.x - pos.x) * (ray.x - pos.x)
			+ (ray.y - pos.y) * (ray.y - pos.y));
	dist /= SIZE_WALL;
	dist *= cos(delta_angle);
	return (dist);
}

void	display_sky(t_mlib *mlib, int w_h, int imi, unsigned int ceil)
{
	int	i;

	i = 0;
	while (i < (HEIGHT - w_h) / 2)
	{
		if (imi < WIDTH && i < HEIGHT)
		{
			my_mlx_pixel_put(&mlib->data, imi, i, ceil);
		}
		i++;
	}
}

void	display_floor(t_mlib *mlib, int w_h, int imi, unsigned int floor)
{
	int	i;

	i = (HEIGHT + w_h) / 2;
	while (i < HEIGHT)
	{
		if (imi < WIDTH && i < HEIGHT)
		{
			my_mlx_pixel_put(&mlib->data, imi, i, floor);
		}
		i++;
	}	
}
