/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcollision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:54:45 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:56:13 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * reset the hit detection data
 **/
static void	reset_hit(t_plyrdata *pd)
{
	pd->det->hit_seg = -1;
	pd->det->hit.xd = -1;
	pd->det->hit.yd = -1;
}

static t_bool	door(t_gamedata *gd, t_vector loc)
{
	t_door	*d;

	d = (t_door *)get_door(gd, loc);
	if (DOOR_AUTO_OPEN && d)
		d->open = true;
	if (d && d->open)
		return (false);
	return (true);
}

/**
 * Detect a wall using the detection points generated
 * by init_detect
 * hit_seg, t_vector hit are used for debuggin to verify
 * location of detection points and where and which
 * point is detecting a wall
 **/
t_bool	wall_collision(t_gamedata *gd, int seg)
{
	int			i;
	t_m_entity	enty;
	t_vector	xy;

	xy.xi = 0;
	xy.yi = 0;
	i = 0;
	while (i < 3)
	{
		xy.xi = (int)(gd->pd->det->vec[gd->pd->det->dir[seg][i]].xd);
		xy.yi = (int)(gd->pd->det->vec[gd->pd->det->dir[seg][i]].yd);
		enty = check_wall(gd, xy);
		if (enty == Wall || enty == Unknown || (enty == Door && door(gd, xy)))
		{
			gd->pd->det->hit_seg = gd->pd->det->dir[seg][i];
			gd->pd->det->hit.xd = gd->pd->det->vec[gd->pd->det->dir[seg][i]].xd;
			gd->pd->det->hit.yd = gd->pd->det->vec[gd->pd->det->dir[seg][i]].yd;
			return (true);
		}
		reset_hit(gd->pd);
		i++;
	}
	return (false);
}
