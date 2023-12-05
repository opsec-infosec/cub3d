/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:55:03 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 11:05:51 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Destroy Window and free up mlx pointer
 **/
static void	free_final(t_gamedata *gd)
{
	if (gd->win && gd->mlx)
		mlx_destroy_window(gd->mlx, gd->win);
	if (gd->mlx)
		free(gd->mlx);
	ft_memset(gd, 0, sizeof(t_gamedata));
}

/**
 * Free the memory allocated in the debug console stores
 **/
static void	free_debug_console(t_gamedata *gd)
{
	int	i;

	if (gd->dbg.color)
		free(gd->dbg.color);
	i = 0;
	while (i < DM)
	{
		if (gd->dbg.str[i])
			free(gd->dbg.str[i]);
		i++;
	}
	if (gd->dbg.str)
		free(gd->dbg.str);
}

/**
 * Free Allocated Structures
 **/
static void	free_structs(t_gamedata *gd)
{
	if (gd->pd && gd->pd->det && gd->pd->det->vec)
		freedetect(gd);
	if (gd->pd)
		free(gd->pd);
	if (gd->mpd)
		free(gd->mpd);
	if (gd->mm)
		free(gd->mm);
	if (gd->pause)
		free(gd->pause);
	if (gd->map)
		free(gd->map);
	free_debug_console(gd);
	free_img_buffer(&(gd)->fb);
}

/**
 * Free game data structures
 * Free textures data structure
 * Free map data
 **/
void	free_memory(t_gamedata *gd)
{
	int	i;

	i = -1;
	if (gd->mpd)
	{
		while (++i < TXTRS)
		{
			if (gd->mpd->txtr[i].path)
				free(gd->mpd->txtr[i].path);
			if (gd->mpd->txtr[i].ptr && gd->mlx)
				mlx_destroy_image(gd->mlx, gd->mpd->txtr[i].ptr);
		}
	}
	if (gd->mm && gd->mm->img->ptr && gd->mlx)
	{
		mlx_destroy_image(gd->mlx, gd->mm->img->ptr);
		free(gd->mm->img);
	}
	free_pause(gd);
	free_sprites(gd);
	i = 0;
	if (gd->mpd && gd->mpd->map)
		ft_free_split(gd->mpd->map);
	free_structs(gd);
	free_final(gd);
}
