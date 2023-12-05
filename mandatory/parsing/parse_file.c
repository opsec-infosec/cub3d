/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:17:00 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 21:53:54 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Validate textures struct and fccolors array
 **/
static int	validate_textures_colors(t_gamedata *gd)
{
	int	i;
	int	j;

	if (!gd->mpd->elements_valid)
	{
		i = 0;
		while (i < TXTRS)
			if (!gd->mpd->txtr[i++].addr)
				return (EXIT_FAILURE);
		i = 0;
		while (i < 2)
		{
			j = 0;
			while (j < 3)
				if (gd->mpd->fccolors[i][j++] == -1)
					return (EXIT_FAILURE);
			i++;
		}
		gd->mpd->elements_valid = true;
	}
	return (EXIT_SUCCESS);
}

static void	get_map_size(t_gamedata *gd)
{
	int		i;
	int		l;
	char	*tmp[2];

	i = 0;
	l = 0;
	gd->mpd->map_col = 0;
	if (gd->mpd->map)
	{
		while (gd->mpd->map[i])
		{
			l = ft_strlen(gd->mpd->map[i]);
			if (l > gd->mpd->map_col)
				gd->mpd->map_col = l;
			i++;
		}
	}
	gd->mpd->map_row = i;
	tmp[0] = ft_itoa(i);
	tmp[1] = ft_itoa(l);
	c_log(gd, ft_strnjoin(4, "Rows: ", tmp[0],
			" | Columns: ", tmp[1]), -1, false);
	free(tmp[0]);
	free(tmp[1]);
}

static void	flush_gnlbuffer(int fd, char *buf)
{
	while (buf)
	{
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
}

/**
 * Parse map config file (*.cub)
 **/
void	parse_validate_file(int fd, t_gamedata *gd)
{
	char	*buf;
	t_bool	mp;

	if (fd < 0)
		print_error(gd, 1);
	buf = get_next_line(fd);
	mp = false;
	while (buf)
	{
		if (mp || (parse_textures(buf, gd) && parse_colors(buf, gd)))
		{
			mp = true;
			if (validate_textures_colors(gd) || parse_map(buf, gd))
			{
				flush_gnlbuffer(fd, buf);
				print_error(gd, 8);
			}
		}
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	get_map_size(gd);
	if (validate_map(gd))
		print_error(gd, 5);
}
