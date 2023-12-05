/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 03:52:43 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 11:06:23 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Capture path and setup MLX Textures
*/
static int	update_textures(t_dir dir, char **data, t_gamedata *gd)
{
	if (!(gd->mpd->txtr[dir].path))
	{
		gd->mpd->txtr[dir].path = ft_strtrim(data[1], "\n");
		gd->mpd->txtr[dir].ptr = mlx_xpm_file_to_image(gd->mlx,
				gd->mpd->txtr[dir].path, &gd->mpd->txtr[dir].size.xi,
				&gd->mpd->txtr[dir].size.yi);
		if (!gd->mpd->txtr[dir].ptr)
			return (EXIT_FAILURE);
		gd->mpd->txtr[dir].addr = mlx_get_data_addr(gd->mpd->txtr[dir].ptr,
				&gd->mpd->txtr[dir].bpp, &gd->mpd->txtr[dir].lsize,
				&gd->mpd->txtr[dir].endian);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * Parse Texture Data
 * Skip blank lines and invalid data
 * until all texture data is collected
*/
int	parse_textures(char *buffer, t_gamedata *gd)
{
	char	**temp;
	int		ret;

	ret = EXIT_FAILURE;
	if (buffer[0] == '\n')
		return (EXIT_SUCCESS);
	if (gd->mpd->elements_valid)
		return (ret);
	temp = ft_splitn(buffer, ' ', 1);
	if (temp && !ft_strncmp(temp[0], "NO", ft_strlen(temp[0])))
		ret = update_textures(NO, temp, gd);
	else if (temp && !ft_strncmp(temp[0], "SO", ft_strlen(temp[0])))
		ret = update_textures(SO, temp, gd);
	else if (temp && !ft_strncmp(temp[0], "EA", ft_strlen(temp[0])))
		ret = update_textures(EA, temp, gd);
	else if (temp && !ft_strncmp(temp[0], "WE", ft_strlen(temp[0])))
		ret = update_textures(WE, temp, gd);
	ft_free_split(temp);
	return (ret);
}
