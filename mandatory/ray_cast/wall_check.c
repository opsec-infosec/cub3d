/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:00:16 by asanthos          #+#    #+#             */
/*   Updated: 2022/12/19 04:54:47 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
1) Calculate change in x & y
2) Create a constant incrementation of 1 for x & y
3) Calculate distance of x to new coordinate
4) Calculate rate of change of sped for x & y
5) Keep adding to distance, compare distances
6) Finally, using the shorter distance value, calculate x or y.
*/

void	cal_delta(t_gamedata *gd)
{
	gd->rc.delta.xd = cos(gd->rc.theta);
	gd->rc.delta.yd = sin(gd->rc.theta);
}

void	vert_sin(t_gamedata *gd)
{
	double	delta_xy;

	delta_xy = gd->rc.delta.xd / gd->rc.delta.yd;
	gd->rc.dist.yd = sqrt(1 + pow(delta_xy, 2));
	gd->rc.ray_ang.yi = gd->pd->location.yd;
	gd->rc.off_set.yd = 0;
	if (gd->rc.delta.yd > 0)
	{
		gd->rc.off_set.yi = 1;
		gd->rc.dir_y = POS;
		gd->rc.off_set.yd = gd->rc.dist.yd
			* (gd->rc.ray_ang.yi + 1 - gd->pd->location.yd);
	}
	else if (gd->rc.delta.yd < 0)
	{
		gd->rc.off_set.yi = -1;
		gd->rc.dir_y = NEG;
		gd->rc.off_set.yd = gd->rc.dist.yd
			* (gd->pd->location.yd - gd->rc.ray_ang.yi);
	}
	else
	{
		gd->rc.off_set.yi = 0;
		gd->rc.dir_y = CONST;
	}
}

void	horizon_sin(t_gamedata *gd)
{
	double	delta_yx;

	delta_yx = gd->rc.delta.yd / gd->rc.delta.xd;
	gd->rc.dist.xd = sqrt(1 + pow(delta_yx, 2));
	gd->rc.ray_ang.xi = gd->pd->location.xd;
	gd->rc.off_set.xd = 0;
	if (gd->rc.delta.xd > 0)
	{
		gd->rc.off_set.xi = 1;
		gd->rc.dir_x = POS;
		gd->rc.off_set.xd = gd->rc.dist.xd
			* (gd->rc.ray_ang.xi + 1 - gd->pd->location.xd);
	}
	else if (gd->rc.delta.xd < 0)
	{
		gd->rc.off_set.xi = -1;
		gd->rc.dir_x = NEG;
		gd->rc.off_set.xd = gd->rc.dist.xd
			* (gd->pd->location.xd - gd->rc.ray_ang.xi);
	}
	else
	{
		gd->rc.off_set.xi = 0;
		gd->rc.dir_y = CONST;
	}
}

void	dir_plyer(t_gamedata *gd)
{
	cal_delta(gd);
	vert_sin(gd);
	horizon_sin(gd);
}

void	wall_check(t_gamedata *gd)
{
	while (check_wall(gd, gd->rc.ray_ang) != Wall)
	{
		if (gd->rc.off_set.xd < gd->rc.off_set.yd)
		{
			gd->rc.off_set.xd += gd->rc.dist.xd;
			gd->rc.ray_ang.xi += gd->rc.off_set.xi;
			gd->rc.side = VERTICAL;
		}
		else
		{
			gd->rc.off_set.yd += gd->rc.dist.yd;
			gd->rc.ray_ang.yi += gd->rc.off_set.yi;
			gd->rc.side = HORIZON;
		}
	}
	if (gd->rc.dir_x == NEG)
		gd->rc.ray_ang.xi += 1;
	if (gd->rc.dir_y == NEG)
		gd->rc.ray_ang.yi += 1;
}
