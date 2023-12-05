/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:00:39 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 03:47:39 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Check that the walls are surrounding the map, 0 next to a space is invalid
 * 0 on the top and bottom lines are invalid
 * 0 under or ontop of line that is null terminated before the 0 is invalid
 * int lines = number of (y) lines in the map
 * char **map = Map Data
 * t_vector pos = is the x and y location, y being the lines and x the rows
 * char c = Character to check, valid chars are 0, N, S, E, W, D
 **/
static int	check_walls(int lines, char **map, t_vector pos, char c)
{
	if (!pos.yi || pos.yi == lines - 1)
	{
		if (map[pos.yi][pos.xi] == c)
			return (EXIT_FAILURE);
	}
	else if ((pos.yi > 0 && pos.yi < lines && map[pos.yi][pos.xi] == c)
		&& (map[pos.yi][pos.xi + 1] == 0x00
		|| map[pos.yi][pos.xi + 1] == ' '
		|| pos.xi >= (int)ft_strlen(map[pos.yi + 1])
		|| pos.xi >= (int)ft_strlen(map[pos.yi - 1])
		|| (pos.xi > 0 && map[pos.yi][pos.xi - 1] == ' ')
		|| map[pos.yi + 1][pos.xi] == ' '
		|| map[pos.yi - 1][pos.xi] == ' '
		|| (pos.xi == 0 && map[pos.yi][pos.xi] == c)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * Check the number of players locations, if more than 1 its an invalid map
 * Check that the player is not outside the map or next to a space and not
 *  surrounded by walls otherwise the player position is invalid
 * int lines = number of (y) lines in the map
 * char **map = Map Data
 * t_vector pos = is the x and y location, y being the lines and x the rows
 * *nploc = incremented on the number of N, S, E or W that are seen on the map
 * 	there should only be one of these in the map (ie only 1 starting position)
 **/
int	check_player_pos(int lines, t_gamedata *gd, t_vector pos, int *nploc)
{
	static char	start_dir[4] = {'N', 'S', 'E', 'W'};
	static int	start_diri[4] = {270, 90, 0, 180};
	int			i;
	char		**map;

	i = 0;
	map = gd->mpd->map;
	while (i < 4 && start_dir[i])
	{
		if (start_dir[i] == map[pos.yi][pos.xi])
		{
			(*nploc)++;
			gd->pd->startdir = start_diri[i];
			gd->pd->pov = (double)gd->pd->startdir * M_PI / 180;
			gd->pd->location.yd = (double)pos.yi + SPEED;
			gd->pd->location.xd = (double)pos.xi + SPEED;
			init_detect(gd->pd);
			if (check_walls(lines, map, pos, start_dir[i]))
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * Entry Pint for validation the map
 * We loop through the Map Data in this function
 *  check walls and player position and doors
 * t_gamedata *gd = Game Data Structure
 **/
int	validate_map(t_gamedata *gd)
{
	t_vector	pos;
	int			nploc;

	if (!gd->mpd->map)
		print_error(gd, 8);
	nploc = 0;
	pos.yi = -1;
	while (gd->mpd->map[++pos.yi])
	{
		pos.xi = -1;
		while (gd->mpd->map[pos.yi][++pos.xi])
		{
			if (check_walls(gd->mpd->map_row, gd->mpd->map, pos, '0'))
				return (EXIT_FAILURE);
			if (check_walls(gd->mpd->map_row, gd->mpd->map, pos, 'D'))
				return (EXIT_FAILURE);
			if (check_player_pos(gd->mpd->map_row, gd, pos, &nploc))
				return (EXIT_FAILURE);
		}
	}
	if (nploc != 1)
		print_error(gd, 6);
	return (EXIT_SUCCESS);
}
