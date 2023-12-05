/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:49:40 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:53:53 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	alloc_pause(t_gamedata *gd)
{
	c_log(gd, ft_strdup("Allocate Pause Asset..."), -1, false);
	gd->pause->p.path = ft_strdup(PGFX);
	gd->pause->p.ptr = mlx_xpm_file_to_image(gd->mlx, gd->pause->p.path,
			&gd->pause->p.size.xi, &gd->pause->p.size.yi);
	if (!gd->pause->p.ptr)
		print_error(gd, 9);
	gd->pause->p.addr = mlx_get_data_addr(gd->pause->p.ptr, &gd->pause->p.bpp,
			&gd->pause->p.lsize, &gd->pause->p.endian);
	if (!gd->pause->p.addr)
		print_error(gd, 2);
}

void	free_pause(t_gamedata *gd)
{
	if (gd->pause && gd->pause->p.ptr && gd->mlx)
	{
		mlx_destroy_image(gd->mlx, gd->pause->p.ptr);
		free(gd->pause->p.path);
	}
}

void	print_pause(t_gamedata *gd)
{
	t_vector	loc;

	loc.yi = (gd->size.yi / 2) - (gd->pause->p.size.yi / 2);
	loc.xi = (gd->size.xi / 2) - (gd->pause->p.size.xi / 2);
	mlx_put_image_to_window(gd->mlx, gd->win, gd->pause->p.ptr, loc.xi, loc.yi);
}

void	mouse_recenter(t_gamedata *gd, int x, int y)
{
	if (x <= gd->size.xi / 2 - MOUSE_HYST || x >= gd->size.xi / 2 + MOUSE_HYST
		|| y <= 0 + MOUSE_HYST || y >= gd->size.yi - MOUSE_HYST)
		mouse_move(gd, (gd->size.xi / 2),
			gd->size.yi / 2);
}

void	mouse_move_plyr(t_gamedata *gd, int x, int y)
{
	if (!gd->pause->hault)
	{
		if (x >= 0 && x <= gd->size.xi && y >= 0 && y <= gd->size.yi)
		{
			if (x <= (gd->size.xi / 2) - MOUSE_HYST)
				gd->pd->pov = clamp(gd->pd->pov - ROTATION, 0, 2 * M_PI);
			else if (x >= (gd->size.xi / 2) + MOUSE_HYST)
				gd->pd->pov = clamp(gd->pd->pov + ROTATION, 0, 2 * M_PI);
		}
		mouse_recenter(gd, x, y);
	}
}
