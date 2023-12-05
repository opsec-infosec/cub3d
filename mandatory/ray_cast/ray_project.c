/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:17:02 by asanthos          #+#    #+#             */
/*   Updated: 2022/12/20 02:08:05 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_dist(t_gamedata *gd)
{
	double	y_val;
	double	x_val;

	gd->rc.angle = fabs(gd->rc.theta - gd->pd->pov);
	if (gd->rc.side == HORIZON)
	{
		gd->rc.ray_ang.yd = gd->rc.ray_ang.yi;
		y_val = gd->rc.ray_ang.yd - gd->pd->location.yd;
		gd->rc.ray_ang.xd = gd->pd->location.xd + (y_val / tan(gd->rc.theta));
		gd->rc.off_set.yd = dist_wall(gd);
		gd->rc.og_dist = gd->rc.off_set.yd * cos(gd->rc.angle);
	}
	else if (gd->rc.side == VERTICAL)
	{
		gd->rc.ray_ang.xd = gd->rc.ray_ang.xi;
		x_val = gd->rc.ray_ang.xd - gd->pd->location.xd;
		gd->rc.ray_ang.yd = gd->pd->location.yd + (tan(gd->rc.theta) * x_val);
		gd->rc.off_set.xd = dist_wall(gd);
		gd->rc.og_dist = gd->rc.off_set.xd * cos(gd->rc.angle);
	}
}

void	set_3d_val(t_gamedata *gd)
{
	get_dist(gd);
	gd->rc.p_rc.wall_len = (HEIGHT / 2) / gd->rc.og_dist;
}

void	draw_3d(t_gamedata *gd, int ray_num)
{
	double	s_wall;
	double	e_wall;
	double	intensity;
	t_dir	dir;

	s_wall = (HEIGHT / 2) - (gd->rc.p_rc.wall_len / 2);
	if (s_wall < 0)
		s_wall = 0;
	e_wall = (gd->rc.p_rc.wall_len / 2) + (HEIGHT / 2);
	if (e_wall >= HEIGHT)
		e_wall = HEIGHT - 1;
	dir = wtext(gd->rc.ray_ang, gd->rc.theta);
	while (s_wall <= e_wall)
	{
		gd->rc.p_rc.w_coor.yi = s_wall;
		gd->rc.p_rc.w_coor.xi = ray_num;
		intensity = ((e_wall - s_wall) / (e_wall + s_wall)) * LIGHT_EFFECT;
		if (!gd->mpd->light_eff || intensity > 1.0)
			intensity = 1.0;
		put_texel(gd, dir, intensity);
		s_wall++;
	}
}
