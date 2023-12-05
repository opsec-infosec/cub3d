/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:14:50 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:53:06 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/** MMGRID can be a whole number of 10 or 20 **/
#define MMGRID 10

/**
 * Calculate partial blocks of minimap.  When moving a small fraction
 *  ie (.25) we draw a partial block on the left and the rest on the right
 * 	as a percentage.
 **/
static void	calc_part_blk(t_gamedata *gd, t_mmos *blk)
{
	t_vector	frac;

	frac.xd = modf(gd->pd->location.xd, &frac.xd);
	blk->rblkx = ceil(frac.xd * ((gd->mm->size.xi) / MMGRID));
	blk->lblkx = ceil((1 - frac.xd) * (gd->mm->size.xi / MMGRID));
	frac.yd = modf(gd->pd->location.yd, &frac.yd);
	blk->tblky = ceil((1 - frac.yd) * (gd->mm->size.yi / MMGRID));
	blk->bblky = ceil(frac.yd * ((gd->mm->size.yi) / MMGRID));
	if (!blk->rblkx)
		blk->rblkx = gd->mm->size.xi / MMGRID;
	if (!blk->bblky)
		blk->bblky = gd->mm->size.yi / MMGRID;
}

/**
 * Wall, Floor, Space Tile Drawing
 *  Draws the entire block of size, write to location loc with color
 *
**/
static t_vector	draw_ent(t_gamedata *gd, t_vector loc, t_vector size, int color)
{
	t_vector	xy;

	xy.yi = loc.yi;
	while (xy.yi < (size.yi + loc.yi) && xy.yi < gd->mm->size.yi)
	{
		xy.xi = loc.xi;
		while (xy.xi < (size.xi + loc.xi) && xy.xi < gd->mm->size.xi)
		{
			put_pixel(gd->mm->img, xy, color);
			xy.xi++;
		}
		xy.yi++;
	}
	return (xy);
}

static t_vector	blk_size(t_gamedata *gd, t_vector blks)
{
	t_mmos		blk;
	t_vector	size;

	size.xi = gd->mm->size.xi / MMGRID;
	size.yi = gd->mm->size.yi / MMGRID;
	calc_part_blk(gd, &blk);
	if (blks.yi == 1)
		size.yi = blk.tblky;
	if (blks.yi > MMGRID)
		size.yi = blk.bblky;
	if (blks.xi == 1)
		size.xi = blk.lblkx;
	if (blks.xi > MMGRID)
		size.xi = blk.rblkx;
	return (size);
}

/**
 * Draws the map grid of one row
 **/
static t_vector	draw_grid(t_gamedata *gd, t_vector xy, t_vector blks)
{
	t_vector	map;
	t_vector	size;

	size = blk_size(gd, blks);
	map.xi = ((int)(gd->pd->location.xd) - ((MMGRID) / 2)) + (blks.xi - 1);
	map.yi = ((int)gd->pd->location.yd) - ((MMGRID) / 2) + (blks.yi - 1);
	if (check_wall(gd, map) == Unknown)
		return (draw_ent(gd, xy, size, 0));
	if (check_wall(gd, map) == Wall)
		return (draw_ent(gd, xy, size, rgb_to_int(128, 0, 128)));
	if (check_wall(gd, map) == Floor)
		return (draw_ent(gd, xy, size, rgb_to_int(45, 45, 45)));
	if (check_wall(gd, map) == Door)
	{
		if (((t_door *)get_door(gd, map))->open)
			return (draw_ent(gd, xy, size, rgb_to_int(0, 128, 0)));
		else
			return (draw_ent(gd, xy, size, rgb_to_int(128, 0, 0)));
	}
	return (xy);
}

/**
 * Make the Minimap -> Draw to Image and put to the screen
**/
void	make_minimap(t_gamedata *gd)
{
	t_vector	xy;
	t_vector	blks;
	t_vector	tmp;

	blks.yi = 1;
	xy.yi = 0;
	while (xy.yi < gd->mm->size.yi)
	{
		xy.xi = 0;
		blks.xi = 1;
		while (xy.xi < gd->mm->size.xi)
		{
			tmp = draw_grid(gd, xy, blks);
			xy.xi = tmp.xi;
			blks.xi++;
		}
		xy.yi = tmp.yi;
		blks.yi++;
	}
	put_player(gd);
	gd->mm->img->size = gd->mm->size;
	put_img_to_fb(gd->mm->img, gd->fb, gd->mm->win_loc);
}
