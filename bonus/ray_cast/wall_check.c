/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:00:16 by asanthos          #+#    #+#             */
/*   Updated: 2022/12/19 00:55:32 by dfurneau         ###   ########.fr       */
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

void	vertical_inter(t_gamedata *gd)
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

void	horizon_inter(t_gamedata *gd)
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

t_bool	check_door_pos(t_gamedata *gd, t_vector vec)
{
	t_door	*res;

	res = (t_door *)get_door(gd, vec);
	if (res && res->open == false)
		return (true);
	return (false);
}

void	wall_check(t_gamedata *gd)
{
	t_bool	wall_hit;

	wall_hit = false;
	while (wall_hit == false)
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
		if (check_wall(gd, gd->rc.ray_ang) == Wall)
			wall_hit = true;
		else if (check_wall(gd, gd->rc.ray_ang) == Door)
		{
			wall_hit = check_door_pos(gd, gd->rc.ray_ang);
			gd->rc.door_hit = check_door_pos(gd, gd->rc.ray_ang);
		}
	}
}
