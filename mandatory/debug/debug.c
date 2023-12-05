/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:06:43 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 22:43:09 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
* Prints Wall Collision hits in bottom of the graphics display
*/
static void	hit_detect(t_gamedata *gd)
{
	char	*tmp[3];

	if (gd->pd->det->hit.xd > 0 && gd->pd->det->hit.yd > 0)
	{
		tmp[0] = ft_dtoa(gd->pd->det->hit.xd, 2);
		tmp[1] = ft_dtoa(gd->pd->det->hit.yd, 2);
		tmp[2] = ft_itoa(gd->pd->det->hit_seg);
		c_log(gd, ft_strnjoin(6, "HIT SEG:", tmp[2], " x:", tmp[0],
				" y:", tmp[1]), rgb_to_int(255, 255, 102), false);
		free(tmp[0]);
		free(tmp[1]);
		free(tmp[2]);
	}
}

/**
 * Mouse Position Debug Info
 *  Stores the mouse x and y position in the c_log store
 **/
static void	mouse_pos(t_gamedata *gd)
{
	char	*tmp[2];

	tmp[0] = ft_itoa(gd->pd->mouse.xi);
	tmp[1] = ft_itoa(gd->pd->mouse.yi);
	c_log(gd, ft_strnjoin(4, "x: ", tmp[0], " y: ", tmp[1]), -1, false);
	free(tmp[0]);
	free(tmp[1]);
}

/**
 * Console Print Log Funciton
 * 	Prints the logs stored with c_log to the MLX Windows
 *  It will automatically free the memory of the stored strings after printing
 **/
static void	p_log(t_gamedata *gd)
{
	size_t	i;

	if (!gd->dbg.str || gd->dbg.n == DM)
		return ;
	gd->dbg.lock = true;
	gd->dbg.n = DM;
	i = 0;
	while (i < gd->dbg.n)
	{
		if (gd->dbg.str[i])
		{
			mlx_string_put(gd->mlx, gd->win, 5, gd->size.yi - ((i * 15) + 5),
				gd->dbg.color[i], gd->dbg.str[i]);
			gd->dbg.color[i] = rgb_to_int(0, 255, 0);
			free(gd->dbg.str[i]);
			gd->dbg.str[i] = NULL;
		}
		i++;
	}
	gd->dbg.lock = false;
}

/**
 * Console Log Function
 *  This stores the message in a stack that holds maximum DM size
 *  char *str must be allocated prior to calling this function
 * 		with either ft_strdup() or ft_strjoin() for example
 *  	as the p_log function will free the *str
 *	int color holds the color to store with the message
	bool pause - causes game to pause
 **/
void	c_log(t_gamedata *gd, char *str, int color, t_bool pause)
{
	size_t	i;

	if (DEBUG && !gd->dbg.lock && gd->dbg.n)
	{
		i = DM - gd->dbg.n;
		if (!gd->dbg.str)
			return ;
		if (!gd->dbg.str[i])
		{
			gd->dbg.str[i] = str;
			if (color >= 0 && color <= INT_MAX)
				gd->dbg.color[i] = color;
			gd->dbg.n--;
		}
	}
	else
		free(str);
	if (pause && gd->pause)
	{
		gd->pause->hault = true;
		print_pause(gd);
		mouse_show(gd);
		redraw(gd);
	}
}

/**
 * Prints debug data to the bottom of the graphics display
 **/
void	debug(t_gamedata *gd)
{
	char	*tmp[4];
	int		i;

	if (DEBUG)
	{
		tmp[0] = ft_dtoa(gd->pd->location.xd, 2);
		tmp[1] = ft_dtoa(gd->pd->location.yd, 2);
		tmp[2] = ft_dtoa(gd->pd->pov * 180.0 / M_PI, 2);
		tmp[3] = ft_dtoa(gd->pd->pov, 3);
		c_log(gd, ft_strnjoin(9, "x:", tmp[0], " y:", tmp[1],
				" pov:", tmp[2], "(", tmp[3], ")"), -1, false);
		i = 0;
		while (i < 4)
			free(tmp[i++]);
		hit_detect(gd);
		if (MOUSE)
			mouse_pos(gd);
		p_log(gd);
	}
}
