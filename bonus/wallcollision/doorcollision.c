/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doorcollision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:54:45 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 16:58:02 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * reset the hit detection data
 **/
static void	reset_hit(t_plyrdata *pd, t_m_entity enty)
{
	(void)enty;
	pd->ddet->hit_seg = 0;
	pd->ddet->hit.xd = 0;
	pd->ddet->hit.yd = 0;
}

/**
 * Detect a Door using the detection points generated
 * by init_detect
 * hit_seg, t_vector hit are used for debuggin to verify
 * location of detection points and where and which
 * point is detecting a wall
 **/
static t_bool	door_cleared(t_gamedata *gd, int seg)
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
		if (enty == Floor || enty == Wall)
			return (false);
		i++;
	}
	return (true);
}

t_bool	door_clear_det(t_gamedata *gd)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (door_cleared(gd, i))
			return (true);
		i++;
	}
	return (false);
}

/**
 * Detect a door using the detection points generated
 * by door_initdetect
 * hit_seg, t_vector hit are used for debuggin to verify
 * location of detection points and where and which
 * point is detecting a wall
 **/
t_bool	door_collision(t_gamedata *gd)
{
	int			i;
	t_m_entity	enty;
	t_vector	xy;
	t_detect	*d;

	xy.xi = 0;
	xy.yi = 0;
	i = 0;
	d = gd->pd->ddet;
	while (i < 3)
	{
		xy.xi = (int)(d->vec[d->dir[0][i]].xd);
		xy.yi = (int)(d->vec[d->dir[0][i]].yd);
		enty = check_wall(gd, xy);
		if (enty == Door)
		{
			d->hit_seg = d->dir[0][i];
			d->hit.xd = d->vec[d->dir[0][i]].xd;
			d->hit.yd = d->vec[d->dir[0][i]].yd;
			return (true);
		}
		reset_hit(gd->pd, enty);
		i++;
	}
	return (false);
}
