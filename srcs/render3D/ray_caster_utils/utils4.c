/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:53:51 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:56:27 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	text_in_n(t_coord ray, t_coord ray_bef)
{
	if (pix_in_n(ray) == 1 && pix_in_e(ray) == 1)
		return (pix_in_n_e(ray, ray_bef));
	if (pix_in_n(ray) == 1 && pix_in_w(ray) == 1)
		return (pix_in_n_w(ray, ray_bef));
	return (pix_in_n(ray));
}

int	text_in_s(t_coord ray, t_coord ray_bef)
{
	if (pix_in_s(ray) == 1 && pix_in_e(ray) == 1)
		return (pix_in_s_e(ray, ray_bef));
	if (pix_in_s(ray) == 1 && pix_in_w(ray) == 1)
	{
		return (pix_in_s_w(ray, ray_bef));
	}
	return (ray.y % SIZE_WALL == 0);
}

float	atan2f_to_ortho(t_vec direction)
{
	float	angle_relative;

	angle_relative = atan2f(direction.y, direction.x);
	if (angle_relative < 0)
	{
		return (angle_relative * (-1));
	}
	return (2 * M_PI - angle_relative);
}

float	get_fov_start(t_general *general)
{
	float	player_angle;
	t_vec	direction;

	direction = general->scene->player.dir;
	player_angle = atan2f(direction.y, direction.x);
	return (player_angle - ((M_PI / 3) / 2));
}

float	get_fov_end(t_general *general)
{
	float	player_angle;
	t_vec	direction;

	direction = general->scene->player.dir;
	player_angle = atan2f(direction.y, direction.x);
	return (player_angle + ((M_PI / 3) / 2));
}
