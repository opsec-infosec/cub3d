/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:47 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 21:53:34 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Put Player on map within offset position
 * uses map_calc to figure out the offset into the image
 * to print the pixel
 **/
void	map_put_player(t_gamedata *gd, t_vector xy, int color)
{
	t_vector	plyr;
	t_vector	pos;
	t_vector	tmp;

	plyr = map_calc(xy, gd);
	pos.yi = -1;
	while (pos.yi < 2)
	{
		tmp.yi = plyr.yi + pos.yi;
		pos.xi = -1;
		while (pos.xi < 2)
		{
			tmp.xi = plyr.xi + pos.xi;
			put_pixel_fb(&gd->fb, tmp, color);
			pos.xi++;
		}
		pos.yi++;
	}
}

/**
 * Wall, Floor, Space Tile Drawing
 * Draws individual blocks on the map block by block
**/
static t_vector	draw_map(t_gamedata *gd, t_vector loc, t_vector size, int color)
{
	t_vector	xy;

	xy.yi = loc.yi;
	while (xy.yi < (size.yi + loc.yi) && xy.yi < gd->map->size.yi)
	{
		xy.xi = loc.xi;
		while (xy.xi < (size.xi + loc.xi) && xy.xi < gd->map->size.xi)
		{
			put_pixel_fb(&gd->fb, xy, color);
			xy.xi++;
		}
		xy.yi++;
	}
	return (xy);
}

/**
 * Draw entire full map using draw_map
 **/
static t_vector	draw_grid(t_gamedata *gd, t_vector xy)
{
	t_vector	map;
	t_vector	size;

	if (gd->mpd->map_col > gd->mpd->map_row)
	{
		map.xi = xy.xi / (gd->map->size.xi / gd->mpd->map_col);
		map.yi = xy.yi / (gd->map->size.yi / gd->mpd->map_col);
		size.xi = (gd->map->size.xi / gd->mpd->map_col);
		size.yi = (gd->map->size.yi / gd->mpd->map_col);
	}
	else
	{
		map.xi = xy.xi / (gd->map->size.xi / gd->mpd->map_row);
		map.yi = xy.yi / (gd->map->size.yi / gd->mpd->map_row);
		size.xi = (gd->map->size.xi / gd->mpd->map_row);
		size.yi = (gd->map->size.yi / gd->mpd->map_row);
	}
	if (check_wall(gd, map) == Unknown)
		return (draw_map(gd, xy, size, 0));
	if (check_wall(gd, map) == Wall)
		return (draw_map(gd, xy, size, rgb_to_int(128, 0, 128)));
	if (check_wall(gd, map) == Floor)
		return (draw_map(gd, xy, size, rgb_to_int(45, 45, 45)));
	return (xy);
}

/**
 * Entry into the make full map
 **/
void	make_map(t_gamedata *gd)
{
	t_vector	xy;
	t_vector	mapxy;

	xy.yi = 0;
	while (xy.yi < gd->map->size.yi)
	{
		xy.xi = 0;
		while (xy.xi < gd->map->size.xi)
		{
			mapxy = draw_grid(gd, xy);
			xy.xi = mapxy.xi;
		}
		xy.yi = mapxy.yi;
	}
	map_put_player(gd, gd->pd->location, rgb_to_int(255, 0, 0));
}
