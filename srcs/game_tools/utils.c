/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:46:45 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 11:46:46 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	hit_a_wall(t_general *general, int x, int y)
{
	char	**matrix;

	matrix = general->scene->map.matrix;
	return (matrix[y / SIZE_WALL][x / SIZE_WALL] == '1');
}

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color < 0)
	{
		printf("\n\nmyPixel : x = %d y = %d\n", x, y);
	}
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
		return (1);
	}
	else
	{
		printf("Pixel inconnu : x = %d y = %d\n", x, y);
		return (-1);
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_coord	create_trgb_reverse(unsigned int color)
{
	t_coord	color_vec;

	color_vec.x = (color >> 16) & 0xFF;
	color_vec.y = (color >> 8) & 0xFF;
	color_vec.z = color & 0xFF;
	return (color_vec);
}

t_vec	vec_normalize(t_vec v)
{
	float	vec3_length;
	t_vec	normalized;

	vec3_length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (vec3_length == 0.0)
	{
		normalized.x = 0.0;
		normalized.y = 0.0;
		normalized.z = 0.0;
	}
	else
	{
		normalized.x = v.x / vec3_length;
		normalized.y = v.y / vec3_length;
		normalized.z = v.z / vec3_length;
	}
	return (normalized);
}
