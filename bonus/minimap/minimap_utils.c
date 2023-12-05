/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:45:05 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 01:50:06 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Returns the door entity (struct) at t_vector loc
 * or if no door, null is returned
 **/
void	*get_door(t_gamedata *gd, t_vector loc)
{
	size_t	n;

	n = 0;
	while (n < gd->mpd->ndoor)
	{
		if (gd->mpd->door[n].loc.xi == loc.xi
			&& gd->mpd->door[n].loc.yi == loc.yi)
			return (&gd->mpd->door[n]);
		n++;
	}
	return (NULL);
}

/**
 * Initialize and allocate image
 *  m->win_loc.xi = WIDTH - m->size.xi - m->size.xi / 2;
 *  m->win_loc.yi = HEIGHT - m->size.yi - m->size.yi / 2;
**/
void	mini_map_init(t_gamedata *gd)
{
	c_log(gd, ft_strdup("Initialize MiniMap..."), -1, false);
	gd->mm->size.xi = WIDTH / 8;
	gd->mm->size.yi = HEIGHT / 8;
	gd->mm->win_loc.xi = (WIDTH - gd->mm->size.xi) - 10;
	gd->mm->win_loc.yi = 10;
	gd->mm->active = true;
	gd->mm->img->ptr = mlx_new_image(gd->mlx, gd->mm->size.xi, gd->mm->size.yi);
	if (!gd->mm->img->ptr)
		print_error(gd, 2);
	gd->mm->img->addr = mlx_get_data_addr(gd->mm->img->ptr, &gd->mm->img->bpp,
			&gd->mm->img->lsize, &gd->mm->img->endian);
	if (!gd->mm->img->addr)
		print_error(gd, 2);
}

/**
 * Checks the double x and double y position
 * Returns Wall, Floor or Unknown
 *  Floor = 0
 *  Wall = 1
 *  Unknown = 2
 **/
t_m_entity	check_wall(t_gamedata *gd, t_vector xy)
{
	if (xy.xi >= 0 && xy.yi >= 0 && xy.yi < gd->mpd->map_row
		&& xy.xi < (int)ft_strlen(gd->mpd->map[xy.yi]))
	{
		if (gd->mpd->map[xy.yi][xy.xi] == '1')
			return (Wall);
		if (gd->mpd->map[xy.yi][xy.xi] == 'D')
			return (Door);
		if (gd->mpd->map[xy.yi][xy.xi] == ' ')
			return (Unknown);
		else
			return (Floor);
	}
	else
		return (Unknown);
}

/**
 * Draw point of view angle
 * on minimap
 **/
static void	put_player_pov(t_gamedata *gd)
{
	t_vector	plyr;
	t_vector	xypov;
	int			dist;

	plyr.xi = (gd->mm->size.xi / 2);
	plyr.yi = (gd->mm->size.yi / 2);
	dist = (gd->mm->size.yi / 2) - 1;
	while (dist >= 0)
	{
		xypov.xi = (int)((cos(gd->pd->pov + (M_PI / 6)) * dist) + plyr.xi);
		xypov.yi = (int)((sin(gd->pd->pov + (M_PI / 6)) * dist) + plyr.yi);
		put_pixel(gd->mm->img, xypov, rgb_to_int(255, 0, 0));
		xypov.xi = (int)((cos(gd->pd->pov - (M_PI / 6)) * dist) + plyr.xi);
		xypov.yi = (int)((sin(gd->pd->pov - (M_PI / 6)) * dist) + plyr.yi);
		put_pixel(gd->mm->img, xypov, rgb_to_int(255, 0, 0));
		dist--;
	}
}

/**
 * Draw the player position in center
 * of minimap
 **/
void	put_player(t_gamedata *gd)
{
	t_vector	plyr;
	t_vector	pos;

	plyr.xi = (gd->mm->size.xi / 2) - 2;
	plyr.yi = (gd->mm->size.yi / 2) - 2;
	pos.yi = 0;
	while (pos.yi < 4)
	{
		pos.xi = 0;
		while (pos.xi < 4)
		{
			put_pixel(gd->mm->img, plyr, rgb_to_int(255, 0, 0));
			plyr.xi++;
			pos.xi++;
		}
		plyr.xi = (gd->mm->size.xi / 2) - 2;
		plyr.yi++;
		pos.yi++;
	}
	put_player_pov(gd);
}
