/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:03:57 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:03:59 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_vec(t_vec vector)
{
	printf("x = %f, ", vector.x);
	printf("y = %f, ", vector.y);
	printf("z = %f", vector.z);
	printf("\n");
}

void	print_coord(t_coord coord)
{
	printf("Coord x = %d ", coord.x);
	printf("y = %d ", coord.y);
	printf("z = %d\n", coord.z);
}

void	print_tab(char **tab)
{
	int	i;

	printf("--------------------------------\n\n");
	i = 0;
	while (tab[i] != NULL)
	{
		printf("[%s] (%d)\n", tab[i], i);
		i++;
	}
	printf("\n---------------------------------\n");
}

void	print_sprite(t_sprite *sprite)
{
	printf("         path = %s\n", sprite->path);
	printf(" sprite width = %d\n", sprite->sprite_w);
	printf("sprite heigth = %d\n", sprite->sprite_h);
	printf("  line length = %d\n", sprite->data_spr.line_length);
	printf("\n");
}
