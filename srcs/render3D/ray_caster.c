/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:53:36 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:59:01 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_caster_utils/utils.h"

void	color_img(t_general *general, int imi, int w_h, t_tab result)
{
	if (w_h < WIDTH)
	{
		display_sky(general->mlib, w_h, imi, general->scene->sky_color);
		display_floor(general->mlib, w_h, imi, general->scene->floor_color);
	}
	if (text_in_s(result.v2, result.v1))
	{
		draw_3d_line_south(general, result.v2, w_h, imi);
	}
	else if (text_in_n (result.v2, result.v1))
	{
		draw_3d_line_north(general, result.v2, w_h, imi);
	}
	else if (pix_in_e(result.v2))
	{
		draw_3d_line_east(general, result.v2, w_h, imi);
	}
	else if (pix_in_w(result.v2))
	{
		draw_3d_line_west(general, result.v2, w_h, imi);
	}
}

void	trace_ray(t_general *general)
{
	int		imageincre;
	float	pl_st_end[3];
	double	angle;
	t_tab	result;
	int		wall_height;

	imageincre = 0;
	pl_st_end[0] = atan2f(general->scene->player.dir.y,
			general->scene->player.dir.x);
	pl_st_end[1] = get_fov_start(general);
	pl_st_end[2] = get_fov_end(general);
	while (imageincre < WIDTH)
	{
		angle = pl_st_end[1]
			+ (pl_st_end[2] - pl_st_end[1]) * imageincre / WIDTH;
		result = find_point_on_screen(general,
				general->scene->player.pos, angle);
		wall_height = round((float)(WIDTH)
				/ get_dist(general->scene->player.pos,
					result.v2, angle - pl_st_end[0]));
		color_img(general, imageincre, wall_height, result);
		imageincre++;
	}
}

int	render_game(t_general *general)
{
	t_mlib	*mlib;

	mlib = general->mlib;
	mlib->data.img_ptr = mlx_new_image(mlib->utils.mlx, WIDTH, HEIGHT);
	mlib->data.addr = mlx_get_data_addr(mlib->data.img_ptr,
			&mlib->data.bits_per_pixel,
			&mlib->data.line_length,
			&mlib->data.endian);
	move(general);
	trace_ray(general);
	mlx_put_image_to_window(mlib->utils.mlx,
		mlib->utils.win, mlib->data.img_ptr, 0, 0);
	mlx_destroy_image(mlib->utils.mlx, mlib->data.img_ptr);
	return (0);
}
