/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:49:28 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 02:07:08 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include <stdio.h>

/**
 * Returns whether xy.xd or xy.yd is a whole number
 * Returns
 * 	1 if xd is a whole number (ie E or W)
 *  0 if yd is a whole number (ie N or S)
 *  -1 if xy and xd is a whole number (ie edge)
 * 		or -1 if both are not whole numbers (in this case its an error)
 **/
static int	get_xy_target(t_vector xy)
{
	t_vector	tmp;
	double		interger;

	tmp.xd = modf(xy.xd, &interger);
	tmp.yd = modf(xy.yd, &interger);
	if (tmp.xd == .0 && tmp.yd == .0)
		return (-1);
	if (tmp.xd == .0)
		return (1);
	if (tmp.yd == .0)
		return (0);
	return (-1);
}

/**
 * Returns the wall texture to use
 * NO, SO, EA or WE
 * use with t_mapdata txtr[wtext(rayhit, angle)]
 * 	from 180 - 270 - 0 = N
 * 	from  180 - 90 - 0 = S
 *  from 270 - 0 - 90 = E
 *  from 90 - 180 - 270 = W
**/
t_dir	wtext(t_vector rloc, double theta)
{
	int	is_ew;

	is_ew = get_xy_target(rloc);
	if (is_ew == 1 && cos(theta) <= 0.0)
		return (WE);
	if (is_ew == 1 && cos(theta) >= 0.0)
		return (EA);
	if (is_ew == 0 && sin(theta) <= 0.0)
		return (NO);
	if (is_ew == 0 && sin(theta) >= 0.0)
		return (SO);
	return (-1);
}

static int	calc_texture_offset(t_gamedata *gd, t_vector ray_ang, t_dir dir)
{
	double	sfactor;

	if (dir == NO || dir == SO)
		sfactor = modf(ray_ang.xd, &sfactor) * gd->mpd->txtr[dir].size.xi;
	else
		sfactor = modf(ray_ang.yd, &sfactor) * gd->mpd->txtr[dir].size.yi;
	return (sfactor);
}

static int	pixel_effect(int color, double intensity)
{
	unsigned int	alpha;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	alpha = (unsigned int)((color & 0xFF000000));
	red = (unsigned int)((color & 0xFF0000) * intensity) & 0xFF0000;
	green = (unsigned int)((color & 0xFF00) * intensity) & 0xFF00;
	blue = (unsigned int)((color & 0xFF) * intensity) & 0xFF;
	return (alpha | red | green | blue);
}

/**
 * SF = (y2 - y1) / (x2 - x1)
 * 	y = texture
 * 	x = wall length
 * SF * In = Out
 **/
void	put_texel(t_gamedata *gd, t_dir dir, double intensity)
{
	double		start;
	double		sf;
	t_vector	xy;

	if (dir != NO && dir != SO && dir != EA && dir != WE)
		return ;
	xy.xi = calc_texture_offset(gd, gd->rc.ray_ang, dir);
	start = (HEIGHT / 2) - (gd->rc.p_rc.wall_len / 2);
	sf = (gd->mpd->txtr[dir].size.yi - 1) / (gd->rc.p_rc.wall_len);
	xy.yi = abs((int)(((double)gd->rc.p_rc.w_coor.yi - start) * sf));
	put_pixel_fb(&gd->fb, gd->rc.p_rc.w_coor,
		pixel_effect(get_pixel(gd->mpd->txtr[dir], xy), intensity));
}
