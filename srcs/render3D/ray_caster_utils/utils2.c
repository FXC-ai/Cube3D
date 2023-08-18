/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:49:17 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:52:24 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pix_in_s(t_coord ray)
{
	return (ray.y % SIZE_WALL == 0);
}

int	pix_in_n(t_coord ray)
{
	return (ray.y % SIZE_WALL == SIZE_WALL - 1);
}

int	pix_in_e(t_coord ray)
{
	return (ray.x % SIZE_WALL == 0);
}

int	pix_in_w(t_coord ray)
{
	return (ray.x % SIZE_WALL == SIZE_WALL - 1);
}
