/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:15:34 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:56:43 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/**
 * Draw the floor and ceiling
 * from the F and C in the config file
 **/
void	draw_floor_ceiling(t_gamedata *gd)
{
	t_vector	xy;
	int			color;
	int			*fc;

	fc = gd->mpd->fccolors[C];
	color = rgb_to_int(fc[R], fc[G], fc[B]);
	xy.yi = -1;
	while (++xy.yi < gd->size.yi / 2)
	{
		xy.xi = -1;
		while (++xy.xi < gd->size.xi)
			put_pixel_fb(&gd->fb, xy, color);
	}
	fc = gd->mpd->fccolors[F];
	color = rgb_to_int(fc[R], fc[G], fc[B]);
	while (xy.yi < gd->size.yi)
	{
		xy.xi = -1;
		while (++xy.xi < gd->size.xi)
			put_pixel_fb(&gd->fb, xy, color);
		xy.yi++;
	}
}

void	draw_crosshair(t_gamedata *gd)
{
	t_vector	xy;

	if (!gd->sprts->fire)
	{
		xy.xi = (gd->size.xi / 2) - 12;
		xy.yi = (gd->size.yi / 2);
		while (xy.xi < (gd->size.xi / 2) + 12)
		{
			put_pixel_fb(&gd->fb, xy, rgb_to_int(255, 0, 0));
			xy.xi++;
		}
		xy.xi = (gd->size.xi / 2);
		xy.yi = (gd->size.yi / 2) - 12;
		while (xy.yi < (gd->size.yi / 2) + 12)
		{
			put_pixel_fb(&gd->fb, xy, rgb_to_int(255, 0, 0));
			xy.yi++;
		}
	}
}
