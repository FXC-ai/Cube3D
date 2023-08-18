/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:55:47 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:56:10 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../render3D.h"

float	get_dist(t_coord pos, t_coord ray, float delta_angle);
void	display_sky(t_mlib *mlib, int w_h, int imi, unsigned int ceil);
void	display_floor(t_mlib *mlib, int w_h, int imi, unsigned int floor);

int		pix_in_s(t_coord ray);
int		pix_in_n(t_coord ray);
int		pix_in_e(t_coord ray);
int		pix_in_w(t_coord ray);

int		pix_in_s_e(t_coord ray, t_coord ray_bef);
int		pix_in_s_w(t_coord ray, t_coord ray_bef);
int		pix_in_n_e(t_coord ray, t_coord ray_bef);
int		pix_in_n_w(t_coord ray, t_coord ray_bef);

int		text_in_n(t_coord ray, t_coord ray_bef);
int		text_in_s(t_coord ray, t_coord ray_bef);
float	atan2f_to_ortho(t_vec direction);
float	get_fov_start(t_general *general);
float	get_fov_end(t_general *general);

#endif