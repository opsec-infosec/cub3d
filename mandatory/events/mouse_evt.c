/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_evt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:52:07 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 04:50:14 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * MOUSE MOVE EVENTS
 * 	MOUSE_HYST = Mouse Hysterisis
*/
int	mouse_evt(int x, int y, t_gamedata *gd)
{
	if (!gd->pause->hault)
	{
		mouse_move_plyr(gd, x, y);
		gd->pd->mouse.yi = y;
		gd->pd->mouse.xi = x;
	}
	return (EXIT_SUCCESS);
}

int	mouse_press_evt(int button, int x, int y, t_gamedata *gd)
{
	(void)x;
	(void)y;
	if (!gd->pause->hault)
	{
		if (button == 1 && !gd->pause->hault)
			gd->sprts->fire = true;
	}
	return (EXIT_SUCCESS);
}
