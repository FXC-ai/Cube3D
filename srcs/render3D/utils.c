/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:54:44 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 14:17:39 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render3D.h"

int	should_stop(t_general *general, t_coord c0)
{
	if (hit_a_wall(general, c0.x, c0.y) != 0)
		return (0);
	return (1);
}

void	set_var(t_coord *v1, t_coord *v2, t_coord c0)
{
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = 0;
	v2->x = c0.x;
	v2->y = c0.y;
	v2->z = 0;
}

void	init_var(int *dx, int *dy, t_coord c0, t_coord c1)
{
	*dx = c1.x - c0.x;
	*dy = c1.y - c0.x;
}
