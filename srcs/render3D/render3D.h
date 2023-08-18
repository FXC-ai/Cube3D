/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3D.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:03:12 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 16:03:13 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER3D_H
# define RENDER3D_H

# include "../../header.h"

/* render3D/ray_caster.c */
t_tab	find_point_on_screen(t_general *general, t_coord c0, float angle);
void	trace_ray(t_general *general);
int		render_game(t_general *general);

/* render3D/3D_wall_render.c */
void	draw_3d_line_north(t_general *g, t_coord ray, int w_h, int imageincre);
void	draw_3d_line_south(t_general *g, t_coord ray, int w_h, int imageincre);
void	draw_3d_line_east(t_general *g, t_coord ray, int w_h, int imageincre);
void	draw_3d_line_west(t_general *g, t_coord ray, int w_h, int imageincre);

/* render3D/get_color.c */
int		get_color_wall_north(t_general *g, int x, int h_wall, int max_wall_h);
int		get_color_wall_south(t_general *g, int x, int h_wall, int mx_wall_h);
int		get_color_wall_east(t_general *g, int x, int h_wall, int max_wall_h);
int		get_color_wall_west(t_general *g, int x, int h_wall, int max_wall_h);

/* utils.c */
void	init_var(int *dx, int *dy, t_coord c0, t_coord c1);
void	set_var(t_coord *v1, t_coord *v2, t_coord c0);
int		should_stop(t_general *general, t_coord c0);

#endif