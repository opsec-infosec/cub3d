/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:06:48 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 04:53:10 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#ifdef LINUX

void	mouse_hide(t_gamedata *gd)
{
	mlx_mouse_hide(gd->mlx, gd->win);
}

void	mouse_show(t_gamedata *gd)
{
	mlx_mouse_show(gd->mlx, gd->win);
}

int	mouse_move(t_gamedata *gd, int x, int y)
{
	return (mlx_mouse_move(gd->mlx, gd->win, x, y));
}

int	mouse_get_pos(t_gamedata *gd, int *x, int *y)
{
	return (mlx_mouse_get_pos(gd->mlx, gd->win, x, y));
}

#endif
