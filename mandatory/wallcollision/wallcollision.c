/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcollision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:54:45 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 04:55:14 by dfurneau         ###   ########.fr       */
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

/**
 * Detect a wall using the detection points generated
 * by initdetect
 * hit_seg, t_vector hit are used for debuggin to verify
 * location of detection points and where and which
 * point is detecting a wall
 **/
t_bool	wall_collision(t_gamedata *gd, int seg)
{
	int			i;
	t_m_entity	entity;
	t_vector	xy;
	t_plyrdata	*d;

	xy.xi = 0;
	xy.yi = 0;
	i = 0;
	d = gd->pd;
	while (i < 3)
	{
		xy.xi = (int)(d->det->vec[d->det->dir[seg][i]].xd);
		xy.yi = (int)(d->det->vec[d->det->dir[seg][i]].yd);
		entity = check_wall(gd, xy);
		if (entity == Wall || entity == Unknown)
		{
			d->det->hit_seg = d->det->dir[seg][i];
			d->det->hit.xd = d->det->vec[d->det->dir[seg][i]].xd;
			d->det->hit.yd = d->det->vec[d->det->dir[seg][i]].yd;
			return (true);
		}
		reset_hit(d);
		i++;
	}
	return (false);
}
