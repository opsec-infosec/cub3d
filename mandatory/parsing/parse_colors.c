/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:54:45 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/21 17:34:23 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	validate_args(char *orig, char **val)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (orig[i])
	{
		if (orig[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (EXIT_FAILURE);
	i = 0;
	count = 0;
	while (val[i++])
		count++;
	if (count != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * Update fccolors structure
 **/
static int	update_fccolor(int fc, char *orig, char **val, t_gamedata *gd)
{
	int	i;
	int	tmp;

	if (!validate_args(orig, val)
		&& gd->mpd->fccolors[fc][R] == -1
		&& gd->mpd->fccolors[fc][G] == -1
		&& gd->mpd->fccolors[fc][B] == -1)
	{
		i = -1;
		while (++i < 3)
		{
			tmp = ft_atoi(val[i]);
			if (tmp >= 0 && tmp <= UCHAR_MAX && ft_strisnumber(val[i]))
				gd->mpd->fccolors[fc][i] = (int)tmp;
			else
				return (EXIT_FAILURE);
		}
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * Parse Colors Elements
 *    		//ttmp = ft_strtrim(temp[1], "\n");
 **/
int	parse_colors(char *buffer, t_gamedata *gd)
{
	char	**elments;
	char	**val;
	char	*strip;
	int		ret;

	ret = EXIT_FAILURE;
	if (gd->mpd->elements_valid)
		return (ret);
	elments = ft_splitn(buffer, ' ', 1);
	if (elments && elments[1])
	{
		strip = ft_strrmstr(elments[1], "\n");
		if (strip)
		{
			val = ft_split(strip, ',');
			if (val && !ft_strncmp(elments[0], "F", ft_strlen(elments[0])))
				ret = update_fccolor(F, strip, val, gd);
			else if (val && !ft_strncmp(elments[0], "C", ft_strlen(elments[0])))
				ret = update_fccolor(C, strip, val, gd);
			ft_free_split(val);
			free(strip);
		}
	}
	ft_free_split(elments);
	return (ret);
}
