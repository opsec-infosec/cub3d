/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:06:27 by asanthos          #+#    #+#             */
/*   Updated: 2022/12/19 04:54:23 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	plot_line(t_gamedata *gd)
{
	t_vector	pnt;

	gd->m_ray.offset.xd = cos(gd->m_ray.theta) * 0.015;
	gd->m_ray.offset.yd = sin(gd->m_ray.theta) * 0.015;
	gd->m_ray.plot.xd = gd->pd->location.xd;
	gd->m_ray.plot.yd = gd->pd->location.yd;
	gd->m_ray.plot.xi = gd->m_ray.plot.xd;
	gd->m_ray.plot.yi = gd->m_ray.plot.yd;
	while (check_wall(gd, gd->m_ray.plot) != Wall
		&& check_wall(gd, gd->m_ray.plot) != Unknown)
	{
		pnt = map_calc(gd->m_ray.plot, gd);
		put_pixel_fb(&gd->fb, pnt, 50);
		gd->m_ray.plot.xd += gd->m_ray.offset.xd;
		gd->m_ray.plot.yd += gd->m_ray.offset.yd;
		gd->m_ray.plot.xi = gd->m_ray.plot.xd;
		gd->m_ray.plot.yi = gd->m_ray.plot.yd;
	}
}

void	mini_rc_init(t_gamedata *gd)
{
	gd->m_ray.theta = gd->pd->pov;
	gd->m_ray.theta = gd->pd->pov - (30.0 * M_PI / 180.0);
	if (gd->m_ray.theta < 0)
		gd->m_ray.theta += 2.0 * M_PI;
}

void	minimap_rays(t_gamedata *gd)
{
	int	i;

	i = 0;
	mini_rc_init(gd);
	while (i < WIDTH)
	{
		plot_line(gd);
		gd->m_ray.theta += ((FOV / WIDTH) * M_PI / 180);
		if (gd->m_ray.theta > 2.0 * M_PI)
			gd->m_ray.theta -= 2.0 * M_PI;
		i++;
	}
}
