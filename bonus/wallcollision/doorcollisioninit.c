/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doorcollisioninit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:31:25 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 02:25:07 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Calculate the detection points and place in the vec array in
 * the structure det
 **/
void	init_door_detect(t_plyrdata *pd)
{
	t_detect	*d;
	double		dist;

	d = pd->ddet;
	dist = DOOR_DISTANCE;
	d->vec[0].xd = (cos(pd->pov) * (SPEED * dist))
		+ pd->location.xd;
	d->vec[0].yd = (sin(pd->pov) * (SPEED * dist))
		+ pd->location.yd;
	d->vec[1].xd = (cos(pd->pov + ((M_PI / 6.0) / 2)) * (SPEED * dist))
		+ pd->location.xd;
	d->vec[1].yd = (sin(pd->pov + ((M_PI / 6.0) / 2)) * (SPEED * dist))
		+ pd->location.yd;
	d->vec[2].xd = (cos(pd->pov - ((M_PI / 6.0) / 2)) * (SPEED * dist))
		+ pd->location.xd;
	d->vec[2].yd = (sin(pd->pov - ((M_PI / 6.0) / 2)) * (SPEED * dist))
		+ pd->location.yd;
}

/**
 * Prints out the detection points to the screen
 * for debugging
 **/
void	print_door_detect(t_gamedata *gd)
{
	int			i;
	t_vector	tmp;

	i = 0;
	while (i < 3)
	{
		tmp = map_calc(gd->pd->ddet->vec[i], gd);
		if (gd->pd->ddet->hit_seg == 0)
			put_pixel_fb(&gd->fb, tmp, rgb_to_int(255, 255, 255));
		else
			put_pixel_fb(&gd->fb, tmp, rgb_to_int(128, 128, 128));
		i++;
	}
}

/**
 * Allocate the detection structure
 * and init the values
 * part of wall collision detection
 **/
void	alloc_door_detect(t_gamedata *gd)
{
	static int	data[1][3] = {{2, 0, 1}};
	int			i;

	c_log(gd, ft_strdup("Initialize Door Detect..."), -1, false);
	i = -1;
	while (++i < 3)
		gd->pd->ddet->dir[0][i] = data[0][i];
	gd->pd->ddet->hit.xd = 0;
	gd->pd->ddet->hit.yd = 0;
	gd->pd->ddet->hit_seg = 0;
}

void	free_door_detect(t_gamedata *gd)
{
	free(gd->pd->ddet->vec);
	free(gd->pd->ddet);
}
