/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:25:48 by asanthos          #+#    #+#             */
/*   Updated: 2022/12/19 00:55:14 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dir_plyer(t_gamedata *gd)
{
	gd->rc.door_hit = false;
	cal_delta(gd);
	vertical_inter(gd);
	horizon_inter(gd);
}

void	rc_init(t_gamedata *gd)
{
	gd->rc.theta = gd->pd->pov;
	gd->rc.theta = gd->pd->pov - (30.0 * M_PI / 180.0);
	if (gd->rc.theta < 0)
		gd->rc.theta += 2 * M_PI;
}

void	ray_cast(t_gamedata *gd)
{
	int		i;

	i = 0;
	rc_init(gd);
	while (i < WIDTH)
	{
		dir_plyer(gd);
		wall_check(gd);
		set_3d_val(gd);
		draw_3d(gd, i);
		gd->rc.theta += ((FOV / WIDTH) * M_PI / 180.0);
		if (gd->rc.theta > 2 * M_PI)
			gd->rc.theta -= 2 * M_PI;
		i++;
	}
}
