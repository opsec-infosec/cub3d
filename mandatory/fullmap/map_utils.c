/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:06:14 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 21:53:34 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_init(t_gamedata *gd)
{
	c_log(gd, ft_strdup("Initialize Full Map..."), -1, false);
	gd->map->active = false;
	gd->map->size.xi = WIDTH;
	gd->map->size.yi = HEIGHT;
}

/**
 * Calculate offset as t_vector into map
 * Returns the offsed as a t_vector that
 * can be used to a call to put_pixel()
 **/
t_vector	map_calc(t_vector xy, t_gamedata *gd)
{
	t_vector	tmp;
	double		sfy;
	double		sfx;

	if (gd->mpd->map_col > gd->mpd->map_row)
	{
		sfx = (gd->map->size.xi / gd->mpd->map_col);
		sfy = (gd->map->size.yi / gd->mpd->map_col);
	}
	else
	{
		sfx = (gd->map->size.xi / gd->mpd->map_row);
		sfy = (gd->map->size.yi / gd->mpd->map_row);
	}
	tmp.xi = (((int)xy.xd) * sfx) + (modf(xy.xd, &xy.xd) * sfx);
	tmp.yi = (((int)xy.yd) * sfy) + (modf(xy.yd, &xy.yd) * sfy);
	return (tmp);
}
