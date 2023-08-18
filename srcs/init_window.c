/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:41:07 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 11:41:48 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	close_window(t_mlib *mlib)
{
	mlx_destroy_window(mlib->utils.mlx, mlib->utils.win);
	exit(0);
}

int	render(t_general *general)
{
	if (general->scene->mini_map == 1)
	{
		render_mini_map(general);
	}
	else
	{
		render_game(general);
	}
	return (1);
}

void	init_window(t_general *general)
{
	general->mlib->utils.win = mlx_new_window(general->mlib->utils.mlx,
			WIDTH,
			HEIGHT,
			"Cube3D");
	mlx_hook(general->mlib->utils.win, 2, 0, key_pression, general);
	mlx_hook(general->mlib->utils.win, 3, 0, key_release, general);
	mlx_loop_hook(general->mlib->utils.mlx, render, general);
	mlx_hook(general->mlib->utils.win, 17, 0, close_window, general->mlib);
	mlx_loop(general->mlib->utils.mlx);
}
