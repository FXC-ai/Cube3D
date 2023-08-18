/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:50:07 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:52:18 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pix_in_s_e(t_coord ray, t_coord ray_bef)
{
	if (ray_bef.x == ray.x - 1 && ray_bef.y == ray.y + 1)
	{
		return (0);
	}
	else if (ray_bef.x == ray.x - 1 && ray_bef.y == ray.y)
	{
		return (0);
	}
	else if (ray_bef.x == ray.x - 1 && ray_bef.y == ray.y - 1)
	{
		return (0);
	}
	else if (ray_bef.x == ray.x && ray_bef.y == ray.y - 1)
	{
		return (1);
	}
	else if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y - 1)
	{
		return (1);
	}
	return (0);
}

int	pix_in_s_w(t_coord ray, t_coord ray_bef)
{
	if (ray_bef.x == ray.x - 1 && ray_bef.y == ray.y - 1)
	{
		return (1);
	}
	else if (ray_bef.x == ray.x && ray_bef.y == ray.y - 1)
	{
		return (1);
	}
	else if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y - 1)
	{
		return (1);
	}
	else if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y)
	{
		return (0);
	}
	else if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y + 1)
	{
		return (0);
	}
	return (1);
}

int	pix_in_n_e(t_coord ray, t_coord ray_bef)
{
	if (ray_bef.x == (int)(ray.x + 1) && ray_bef.y == (int)(ray.y + 1))
	{
		return (1);
	}
	else if (ray_bef.x == (int)ray.x && ray_bef.y == (int)(ray.y + 1))
	{
		return (1);
	}
	else if (ray_bef.x == (int)(ray.x - 1) && ray_bef.y == (int)(ray.y + 1))
	{
		return (0);
	}
	else if (ray_bef.x == (int)(ray.x - 1) && ray_bef.y == (int)(ray.y))
	{
		return (0);
	}
	else if (ray_bef.x == (int)(ray.x - 1) && ray_bef.y == (int)(ray.y - 1))
	{
		return (0);
	}
	return (1);
}

int	pix_in_n_w(t_coord ray, t_coord ray_bef)
{
	if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y - 1)
	{
		return (0);
	}
	else if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y)
	{
		return (0);
	}
	else if (ray_bef.x == ray.x + 1 && ray_bef.y == ray.y + 1)
	{
		return (1);
	}
	else if (ray_bef.x == ray.x && ray_bef.y == ray.y + 1)
	{
		return (1);
	}
	else if (ray_bef.x == ray.x - 1 && ray_bef.y == ray.y + 1)
	{
		return (1);
	}
	return (0);
}
