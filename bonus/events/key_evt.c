/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_evt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:35:59 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 16:57:44 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * WINDOWS DESTROY EVENT
 * ESC, LEFT RIGHT ARROWS
 **/
int	windestroy_evt(t_gamedata *gd)
{
	free_memory(gd);
	exit(EXIT_SUCCESS);
}

static void	door_open_close(t_gamedata *gd)
{
	t_door		*door;
	t_vector	xy;

	xy.xi = (int)(gd->pd->ddet->vec[gd->pd->ddet->hit_seg].xd);
	xy.yi = (int)(gd->pd->ddet->vec[gd->pd->ddet->hit_seg].yd);
	door = (t_door *)get_door(gd, xy);
	if (!door)
		return ;
	if (door_collision(gd) && !door->open)
	{
		door->open = true;
		return ;
	}
	if (door_collision(gd) && !door_clear_det(gd) && door->open)
	{
		door->open = false;
		return ;
	}
}

/**
 * KEYPRESS SPECIAL EVENT
 * ESC, LEFT, RIGHT
 * 6.28319 rad (2 * PI) = 360 degrees (rad * 180/PI)
 **/
static void	keypress_special_evt(int keycode, t_gamedata *gd)
{
	if (keycode == KEY_LEFT)
		gd->pd->pov = clamp(gd->pd->pov - ROTATION, 0, 2 * M_PI);
	if (keycode == KEY_RIGHT)
		gd->pd->pov = clamp(gd->pd->pov + ROTATION, 0, 2 * M_PI);
	if (keycode == KEY_SPACE)
		gd->mm->active = !gd->mm->active;
	if (keycode == KEY_M)
		gd->map->active = !gd->map->active;
	if (keycode == KEY_L_SHIFT)
		gd->sprts->fire = true;
	if (keycode == KEY_E)
		door_open_close(gd);
}

static void	pause_evt(t_gamedata *gd)
{
	gd->pause->hault = !gd->pause->hault;
	if (MOUSE)
	{
		if (gd->pause->hault)
			mouse_show(gd);
		else
		{
			mouse_hide(gd);
			mouse_recenter(gd, gd->size.xi / 2, gd->size.yi / 2);
		}
	}
	redraw(gd);
}

/**
 * KEYPRESS EVENTS
 * WASD, SPACE
 *  If paused, we don't process any other keys
 * 	gd->pause->hault = true if paused
 **/
int	keypress_evt(int keycode, t_gamedata *gd)
{
	t_plyrdata	*pd;

	pd = gd->pd;
	if (keycode == KEY_ESC)
		windestroy_evt(gd);
	if (keycode == KEY_P)
		pause_evt(gd);
	if (gd->pause->hault)
		return (EXIT_SUCCESS);
	if (keycode == KEY_W && !wall_collision(gd, 0))
		gd->pd->location = pol_cart(pd->location, pd->pov, SPEED);
	if (keycode == KEY_S && !wall_collision(gd, 1))
		gd->pd->location = pol_cart(pd->location, pd->pov, -1 * SPEED);
	if (keycode == KEY_D && !wall_collision(gd, 2))
		gd->pd->location = pol_cart(pd->location, pd->pov + M_PI_2, SPEED);
	if (keycode == KEY_A && !wall_collision(gd, 3))
		gd->pd->location = pol_cart(pd->location, pd->pov + M_PI_2, -1 * SPEED);
	keypress_special_evt(keycode, gd);
	return (EXIT_SUCCESS);
}
