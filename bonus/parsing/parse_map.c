/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:39:57 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/21 17:52:34 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Check map data to see if it is a map
 * Validate only 1, 0, E, W, N, S
 **/
static int	check_is_map(char *buffer)
{
	char			*tmp;
	int				ret;
	int				i;

	ret = EXIT_SUCCESS;
	tmp = ft_strrmstr(buffer, " \n");
	if (tmp && !ret)
	{
		i = 0;
		while (tmp[i] && !ret)
		{
			if (tmp[i] != '1' && tmp[i] != '0' && tmp[i] != 'N'
				&& tmp[i] != 'E' && tmp[i] != 'S' && tmp[i] != 'W'
				&& tmp[i] != 'D')
				ret = EXIT_FAILURE;
			i++;
		}
	}
	else
		ret = EXIT_FAILURE;
	if (tmp)
		free(tmp);
	return (ret);
}

/**
 * Parse map data, does not validate
 * data is in correct positions
 **/
int	parse_map(char *buffer, t_gamedata *gd)
{
	static int	i = 0;
	char		*tmp;

	tmp = ft_strrmstr(buffer, " \n");
	if (!check_is_map(buffer) && (tmp && tmp[0]))
	{
		free(tmp);
		gd->mpd->map = (char **)ft_realloc(gd->mpd->map,
				sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
		if (!gd->mpd->map)
			return (EXIT_FAILURE);
		gd->mpd->map[i] = ft_strtrim(buffer, "\n");
		gd->mpd->map[i + 1] = 0x00;
		if (!gd->mpd->map[i])
			return (EXIT_FAILURE);
		i++;
	}
	else
	{
		if (tmp)
			free(tmp);
		if (i >= 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
