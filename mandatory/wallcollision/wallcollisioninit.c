/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcollisioninit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:31:25 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 04:55:21 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Calculate the detection points and place in the vec array in
 * the structure det
 **/
void	initdetect(t_plyrdata *pd)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		pd->det->vec[i].xd = (cos(pd->pov + ((i * M_PI_4))) * (SPEED * 2))
			+ pd->location.xd;
		pd->det->vec[i].yd = (sin(pd->pov + ((i * M_PI_4))) * (SPEED * 2))
			+ pd->location.yd;
		i++;
	}
}

/**
 * Prints out the detection points to the screen
 * for debugging
 **/
void	printdetect(t_gamedata *gd)
{
	int			i;
	t_vector	tmp;

	i = 0;
	while (i < 8)
	{
		tmp = map_calc(gd->pd->det->vec[i], gd);
		if (i == 0)
			put_pixel_fb(&gd->fb, tmp, rgb_to_int(0, 255, 0));
		else if (i == gd->pd->det->hit_seg)
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
void	allocdetect(t_gamedata *gd)
{
	static int	data[4][3] = {{7, 0, 1}, {3, 4, 5}, {1, 2, 3}, {5, 6, 7}};
	int			i;
	int			j;

	c_log(gd, ft_strdup("Initialize Wall Detect..."), -1, false);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			gd->pd->det->dir[i][j] = data[i][j];
	}
	gd->pd->det->hit.xd = 0;
	gd->pd->det->hit.yd = 0;
	gd->pd->det->hit_seg = 0;
}

void	freedetect(t_gamedata *gd)
{
	free(gd->pd->det->vec);
	free(gd->pd->det);
}
