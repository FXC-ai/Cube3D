/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pixel_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:39:52 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 16:03:58 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render3D.h"

static void	increment_or_decrement(int *n, int dn)
{
	if (dn > 0)
		(*n)++;
	else
		(*n)--;
}

static t_tab	p_ew(t_general *general, t_coord c0, t_coord c1)
{
	int		dx;
	int		dy;
	float	err;
	t_tab	r;

	err = 0.5;
	init_var(&dx, &dy, c0, c1);
	while (42)
	{
		if (err > 1.001f)
		{
			increment_or_decrement(&c0.y, dy);
			err -= 1.0f;
			set_var(&r.v1, &r.v2, c0);
			if (should_stop(general, c0) == 0)
				break ;
		}
		err += fabs((float) dy / (float) dx);
		increment_or_decrement(&c0.x, dx);
		set_var(&r.v1, &r.v2, c0);
		if (should_stop(general, c0) == 0)
			break ;
	}
	return (r);
}

static t_tab	p_sn(t_general *general, t_coord c0, t_coord c1)
{
	int		dx;
	int		dy;
	float	err;
	t_tab	r;

	err = 0.5f;
	init_var(&dx, &dy, c0, c1);
	while (42)
	{
		if (err > 1.001f)
		{
			increment_or_decrement(&c0.x, dx);
			err -= 1.0f;
			set_var(&r.v1, &r.v2, c0);
			if (should_stop(general, c0) == 0)
				break ;
		}
		err += fabs((float) dx / (float) dy);
		increment_or_decrement(&c0.y, dy);
		set_var(&r.v1, &r.v2, c0);
		if (should_stop(general, c0) == 0)
			break ;
	}
	return (r);
}

t_tab	find_point_on_screen(t_general *general, t_coord c0, float angle)
{
	int		dx;
	int		dy;
	t_vec	c1;

	c1.x = ((float)c0.x + cos(angle) * 2000000);
	c1.y = ((float)c0.y + sin(angle) * 2000000);
	dx = c1.x - c0.x;
	dy = c1.y - c0.x;
	if (abs(dx) >= abs(dy))
	{
		return (p_ew(general, c0, (t_coord){round(c1.x), round(c1.y), 0}));
	}
	else
	{
		return (p_sn(general, c0, (t_coord){round(c1.x), round(c1.y), 0}));
	}
}
