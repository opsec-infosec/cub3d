/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:37:07 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:54:21 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_bool	is_plyr(char c)
{
	if (c == 'E' || c == 'W' || c == 'N' || c == 'S')
		return (true);
	return (false);
}

static int	validate_door(t_mapdata *mpd)
{
	size_t		i;
	t_vector	loc;

	i = 0;
	while (i < mpd->ndoor)
	{
		loc.xi = mpd->door[i].loc.xi;
		loc.yi = mpd->door[i].loc.yi;
		if (!((mpd->map[loc.yi - 1][loc.xi] == '1'
				&& (mpd->map[loc.yi][loc.xi + 1] == '0'
				|| is_plyr(mpd->map[loc.yi][loc.xi + 1]))
				&& mpd->map[loc.yi + 1][loc.xi] == '1'
				&& (mpd->map[loc.yi][loc.xi - 1] == '0'
				|| is_plyr(mpd->map[loc.yi][loc.xi - 1])))
				|| ((mpd->map[loc.yi - 1][loc.xi] == '0'
				|| is_plyr(mpd->map[loc.yi - 1][loc.xi]))
				&& mpd->map[loc.yi][loc.xi + 1] == '1'
				&& (mpd->map[loc.yi + 1][loc.xi] == '0'
				|| is_plyr(mpd->map[loc.yi + 1][loc.xi]))
				&& mpd->map[loc.yi][loc.xi - 1] == '1')))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	get_door_loc(t_mapdata *mpd)
{
	t_vector	xy;
	int			i;

	i = 0;
	xy.yi = 0;
	while (mpd->map[xy.yi])
	{
		xy.xi = 0;
		while (mpd->map[xy.yi][xy.xi])
		{
			if (mpd->map[xy.yi][xy.xi] == 'D')
				mpd->door[i++].loc = xy;
			xy.xi++;
		}
		xy.yi++;
	}
}

static size_t	count_doors(t_mapdata *mpd)
{
	int		x;
	int		y;
	size_t	count;

	count = 0;
	y = 0;
	while (mpd->map[y])
	{
		x = 0;
		while (mpd->map[y][x])
		{
			if (mpd->map[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	parse_doors(t_gamedata *gd)
{
	size_t	count;
	char	*tmp;

	count = count_doors(gd->mpd);
	gd->mpd->ndoor = count;
	tmp = ft_itoa((int)count);
	c_log(gd, ft_strnjoin(2, "Door Count: ", tmp), -1, false);
	free(tmp);
	if (count == 0)
		return (EXIT_SUCCESS);
	gd->mpd->door = (t_door *)ft_calloc(count, sizeof(t_door));
	if (!gd->mpd->door)
		print_error(gd, 2);
	get_door_loc(gd->mpd);
	if (validate_door(gd->mpd))
		print_error(gd, 4);
	return (EXIT_SUCCESS);
}
