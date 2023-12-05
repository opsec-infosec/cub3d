/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_osx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:06:48 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:53:43 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#ifdef OSX

void	mouse_hide(t_gamedata *gd)
{
	(void)gd;
	mlx_mouse_hide();
}

void	mouse_show(t_gamedata *gd)
{
	(void)gd;
	mlx_mouse_show();
}

int	mouse_move(t_gamedata *gd, int x, int y)
{
	return (mlx_mouse_move(gd->win, x, y));
}

int	mouse_get_pos(t_gamedata *gd, int *x, int *y)
{
	return (mlx_mouse_get_pos(gd->win, x, y));
}

#endif
