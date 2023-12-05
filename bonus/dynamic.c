/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:47:42 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 03:56:55 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/**
 * Check map is not bigger than our display
 **/
static t_bool	map_ok(t_gamedata *gd)
{
	if (gd->mpd->map_col > WIDTH || gd->mpd->map_row > HEIGHT)
		return (false);
	return (true);
}

static void	print_map_error(t_gamedata *gd)
{
	t_vector	xy;

	xy.yi = 0;
	while (xy.yi < HEIGHT)
	{
		xy.xi = 0;
		while (xy.xi < WIDTH)
		{
			put_pixel_fb(&gd->fb, xy, rgb_to_int(0, 0, 0));
			xy.xi++;
		}
		xy.yi++;
	}
	put_img_to_window(&gd->fb);
	mlx_string_put(gd->mlx, gd->win, ((WIDTH / 2) - 70),
		HEIGHT / 2, rgb_to_int(255, 0, 0), "MAP TOO BIG TO DISPLAY");
}

static void	redraw_images(t_gamedata *gd)
{
	if (gd->map->active && !map_ok(gd))
		print_map_error(gd);
	if (gd->pause->hault)
		print_pause(gd);
	if (!gd->map->active)
		animate_sprite(gd);
}

/**
 * Redraw the graphics to the Screen
 **/
void	redraw(t_gamedata *gd)
{
	if (gd->win && gd->mlx)
	{
		init_detect(gd->pd);
		init_door_detect(gd->pd);
		draw_floor_ceiling(gd);
		ray_cast(gd);
		draw_crosshair(gd);
	}
	if (gd->mm->active && !gd->map->active)
		make_minimap(gd);
	if (gd->map->active && map_ok(gd))
	{
		make_map(gd);
		minimap_rays(gd);
		print_detect(gd);
		print_door_detect(gd);
	}
	put_img_to_window(&gd->fb);
	redraw_images(gd);
	debug(gd);
}
