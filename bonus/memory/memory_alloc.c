/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:32:58 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/22 00:59:46 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	debug_init(t_gamedata *gd)
{
	int	i;

	gd->dbg.n = DM;
	gd->dbg.str = (char **)malloc(sizeof(char *) * gd->dbg.n);
	gd->dbg.color = (int *)malloc(sizeof(int) * gd->dbg.n);
	if (!gd->dbg.str || !gd->dbg.color)
		print_error(gd, 2);
	i = 0;
	while (i < DM)
	{
		gd->dbg.str[i] = NULL;
		gd->dbg.color[i++] = rgb_to_int(0, 255, 0);
	}
	gd->dbg.lock = false;
}

static void	mouse_init(t_gamedata *gd)
{
	if (gd->pause->hault)
	{
		mouse_move(gd, gd->size.xi / 2, gd->size.yi / 2);
		mouse_hide(gd);
		gd->pd->mouse.xi = 0;
		gd->pd->mouse.yi = 0;
	}
}

/**
 * Initialize texture structure with 0
 * Initialize fccolor array with -1
 * Initialize map with NULLs
 * Initialize player data with 0
 **/
static void	struct_init(t_gamedata *gd)
{
	int	i;

	i = 0;
	c_log(gd, ft_strdup("Initialize Memory..."), -1, false);
	while (i < TXTRS)
		ft_memset(&gd->mpd->txtr[i++], 0, sizeof(t_textures));
	i = 0;
	while (i < 2)
		ft_memset(&gd->mpd->fccolors[i++], -1, sizeof(int) * 3);
	gd->mpd->map = NULL;
	gd->mpd->door = NULL;
	gd->mpd->elements_valid = false;
	gd->pause->hault = false;
	gd->mpd->light_eff = EN_LIGHT_EFFECT;
	ft_memset(&gd->fb.img[0], 0, sizeof(t_textures));
	ft_memset(&gd->fb.img[1], 0, sizeof(t_textures));
	alloc_detect(gd);
	alloc_door_detect(gd);
	mini_map_init(gd);
	map_init(gd);
}

/**
 * Allocate game data structure
 * FREE REQ
 **/
void	allocate(t_gamedata *gd)
{
	c_log(gd, ft_strdup("Allocate Memory..."), -1, false);
	gd->mpd = (t_mapdata *)malloc(sizeof(t_mapdata));
	gd->pd = (t_plyrdata *)malloc(sizeof(t_plyrdata));
	gd->mm = (t_minimap *)malloc(sizeof(t_minimap));
	gd->map = (t_map *)malloc(sizeof(t_map));
	gd->pause = (t_pause *)malloc(sizeof(t_pause));
	if (!gd->mm || !gd->mpd || !gd->pd || !gd->map || !gd->pause)
		print_error(gd, 2);
	gd->mm->img = (t_textures *)malloc(sizeof(t_textures));
	gd->pd->det = (t_detect *)malloc(sizeof(t_detect));
	gd->pd->ddet = (t_detect *)malloc(sizeof(t_detect));
	if (!gd->mm->img || !gd->pd->det || !gd->pd->ddet)
		print_error(gd, 2);
	gd->pd->det->vec = (t_vector *)malloc(sizeof(t_vector) * 8);
	gd->pd->ddet->vec = (t_vector *)malloc(sizeof(t_vector) * 3);
	if (!gd->pd->det->vec || !gd->pd->ddet->vec)
		print_error(gd, 2);
	struct_init(gd);
	if (allocate_img_buffer(gd->mlx, gd->win, &gd->fb, gd->size))
		print_error(gd, 2);
	alloc_pause(gd);
	alloc_sprites(gd);
	if (MOUSE)
		mouse_init(gd);
}

char	*memory_usage(void)
{
	struct rusage	rmemory;
	double			mem;

	getrusage(RUSAGE_SELF, &rmemory);
	mem = (rmemory.ru_maxrss / 1048576.0);
	return (ft_dtoa(mem, 1));
}
