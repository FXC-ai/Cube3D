/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:46:43 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 16:13:30 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

float	rad_to_deg(float angle)
{
	return ((angle * 180) / M_PI);
}

float	deg_to_rad(float angle)
{
	return ((angle * M_PI) / 180);
}

int	size_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count] != NULL)
		count++;
	return (count);
}

void	ft_free_tabs(char **tab)
{
	int	i;
	int	h;

	h = size_tab(tab);
	i = 0;
	while (i <= h)
	{
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	free(tab);
}

t_coord	convertcoord2d(t_coord pos)
{
	t_coord	pos2d;

	pos2d.x = (pos.x * SCALE_MINI_MAP) / SIZE_WALL;
	pos2d.y = (pos.y * SCALE_MINI_MAP) / SIZE_WALL;
	return (pos2d);
}
