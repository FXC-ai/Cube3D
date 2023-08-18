/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:25:56 by vgiordan          #+#    #+#             */
/*   Updated: 2023/07/26 12:01:47 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	init_var(int *dx, int *dy, t_coord c0, t_coord c1)
{
	*dx = c1.x - c0.x;
	*dy = c1.y - c0.x;
}

static void	draw1(t_general *general, t_coord c0, t_coord c1, int c)
{
	int		dx;
	int		dy;
	float	err;

	err = 0.5;
	init_var(&dx, &dy, c0, c1);
	while (42)
	{
		if (err > 1.001f)
		{
			if (dy > 0)
				c0.y++;
			else
				c0.y--;
			err -= 1.0f;
		}
		my_mlx_pixel_put(&(general->mlib->data), c0.x, c0.y, c);
		err += fabs((float) dy / (float)dx);
		if (c0.x == c1.x)
			break ;
		if (dx > 0)
			c0.x++;
		else
			c0.x--;
	}
}

static void	draw2(t_general *general, t_coord c0, t_coord c1, int c)
{
	int		dx;
	int		dy;
	float	err;

	err = 0.5f;
	init_var(&dx, &dy, c0, c1);
	while (42)
	{
		if (err > 1.001f)
		{
			if (dx > 0)
				c0.x++;
			else
				c0.x--;
			err -= 1.0f;
		}
		my_mlx_pixel_put(&(general->mlib->data), c0.x, c0.y, c);
		err += fabs((float) dx / (float) dy);
		if (y0 == y1)
			break ;
		if (dy > 0)
			c0.y++;
		else
			c0.y--;
	}
}

void	calculate_ray(t_general *general, t_coord c0, t_coord c1, int c)
{
	int		dx;
	int		dy;

	dx = c1.x - c0.x;
	dy = c1.y - c0.x;
	if (abs(dx) >= abs(dy))
	{
		draw1(general, c0, c1, c);
	}
	else
	{
		draw2(general, c0, c1, c);
	}
}
