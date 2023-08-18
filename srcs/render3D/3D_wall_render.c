/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_wall_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:04:06 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 16:04:07 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render3D.h"

void	draw_3d_line_west(t_general *g, t_coord ray, int w_h, int imi)
{
	int				i;
	unsigned int	clr;

	i = 0;
	if ((HEIGHT - w_h) / 2 > 0)
	{
		while (i < w_h)
		{
			clr = get_color_wall_west(g, ray.y, i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, (HEIGHT - w_h) / 2 + i, clr);
			i++;
		}
	}
	else
	{
		while (i < HEIGHT)
		{
			clr = get_color_wall_west(g, ray.y, (w_h - HEIGHT) / 2 + i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, i, clr);
			i++;
		}
	}
}

void	draw_3d_line_east(t_general *g, t_coord ray, int w_h, int imi)
{
	int				i;
	unsigned int	clr;

	i = 0;
	if ((HEIGHT - w_h) > 0)
	{
		while (i < w_h)
		{
			clr = get_color_wall_east(g, ray.y, i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, (HEIGHT - w_h) / 2 + i, clr);
			i++;
		}
	}
	else
	{
		while (i < HEIGHT)
		{
			clr = get_color_wall_east(g, ray.y, (w_h - HEIGHT) / 2 + i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, i, clr);
			i++;
		}
	}
}

void	draw_3d_line_south(t_general *g, t_coord ray, int w_h, int imi)
{
	int				i;
	unsigned int	clr;

	i = 0;
	if ((HEIGHT - w_h) / 2 > 0)
	{
		while (i < w_h)
		{
			clr = get_color_wall_south(g, ray.x, i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, (HEIGHT - w_h) / 2 + i, clr);
			i++;
		}
	}
	else
	{
		while (i < HEIGHT)
		{
			clr = get_color_wall_south(g, ray.x, (w_h - HEIGHT) / 2 + i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, i, clr);
			i++;
		}
	}
}

void	draw_3d_line_north(t_general *g, t_coord ray, int w_h, int imi)
{
	int				i;
	unsigned int	clr;

	i = 0;
	if ((HEIGHT - w_h) / 2 > 0)
	{
		while (i < w_h)
		{
			clr = get_color_wall_north(g, ray.x, i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, (HEIGHT - w_h) / 2 + i, clr);
			i++;
		}
	}
	else
	{
		while (i < HEIGHT)
		{
			clr = get_color_wall_north(g, ray.x, (w_h - HEIGHT) / 2 + i, w_h);
			my_mlx_pixel_put(&g->mlib->data, imi, i, clr);
			i++;
		}
	}
}
