/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:37:57 by vgiordan          #+#    #+#             */
/*   Updated: 2023/08/17 15:36:15 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	key_pression(int keycode, t_general *general)
{
	if (keycode == KEY_W)
		general->keys->w = 1;
	else if (keycode == KEY_A)
		general->keys->a = 1;
	else if (keycode == KEY_S)
		general->keys->s = 1;
	else if (keycode == KEY_D)
		general->keys->d = 1;
	else if (keycode == KEY_Q)
		general->keys->q = 1;
	else if (keycode == KEY_R)
		general->keys->r = 1;
	else if (keycode == KEY_ARR_R)
		general->keys->arrow_r = 1;
	else if (keycode == KEY_ARR_L)
		general->keys->arrow_l = 1;
	else if (keycode == KEY_M)
		general->scene->mini_map ^= 1;
	else if (keycode == 53)
		exit(0);
	return (1);
}

int	key_release(int keycode, t_general *general)
{
	if (keycode == KEY_W)
		general->keys->w = 0;
	else if (keycode == KEY_A)
		general->keys->a = 0;
	else if (keycode == KEY_S)
		general->keys->s = 0;
	else if (keycode == KEY_D)
		general->keys->d = 0;
	else if (keycode == KEY_Q)
		general->keys->q = 0;
	else if (keycode == KEY_R)
		general->keys->r = 0;
	else if (keycode == KEY_ARR_R)
		general->keys->arrow_r = 0;
	else if (keycode == KEY_ARR_L)
		general->keys->arrow_l = 0;
	return (0);
}

int	move(t_general *g)
{
	t_coord	n_p;
	t_coord	c_p;
	t_vec	dir;
	float	a;

	c_p = g->scene->player.pos;
	dir = g->scene->player.dir;
	s_key(g, &c_p, &n_p, &dir);
	w_key(g, &c_p, &n_p, &dir);
	d_key(g, &c_p, &n_p, &dir);
	a_key(g, &c_p, &n_p, &dir);
	if (g->keys->arrow_l == 1)
	{
		a = atan2f(g->scene->player.dir.y, g->scene->player.dir.x);
		a -= R_SPEED;
		g->scene->player.dir.x = cosf(a);
		g->scene->player.dir.y = sinf(a);
	}
	if (g->keys->arrow_r == 1)
	{
		a = atan2f(g->scene->player.dir.y, g->scene->player.dir.x) + R_SPEED;
		g->scene->player.dir.x = cosf(a);
		g->scene->player.dir.y = sinf(a);
	}
	return (1);
}
