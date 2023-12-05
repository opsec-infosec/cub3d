/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:29:54 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 02:28:16 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_sprites(t_gamedata *gd)
{
	int		i;
	char	*tmp;

	i = 0;
	c_log(gd, ft_strdup("Initialize Sprites..."), -1, false);
	while (i < FRM)
	{
		tmp = ft_itoa(i);
		gd->sprts->txtr[i].path = ft_strnjoin(3, SGFX, tmp, ".xpm");
		free(tmp);
		if (!gd->sprts->txtr[i].path)
			print_error(gd, 2);
		gd->sprts->txtr[i].ptr = mlx_xpm_file_to_image(gd->mlx,
				gd->sprts->txtr[i].path,
				&gd->sprts->txtr[i].size.xi, &gd->sprts->txtr[i].size.yi);
		if (!gd->sprts->txtr[i].ptr)
			print_error(gd, 9);
		gd->sprts->txtr[i].addr = mlx_get_data_addr(gd->sprts->txtr[i].ptr,
				&gd->sprts->txtr[i].bpp, &gd->sprts->txtr[i].lsize,
				&gd->sprts->txtr[i].endian);
		if (!gd->sprts->txtr[i].addr)
			print_error(gd, 2);
		i++;
	}
}

void	alloc_sprites(t_gamedata *gd)
{
	int	i;

	c_log(gd, ft_strdup("Allocate Sprites..."), -1, false);
	gd->sprts = (t_sprt *)malloc(sizeof(t_sprt));
	if (!gd->sprts)
		print_error(gd, 2);
	gd->sprts->txtr = (t_textures *)malloc(sizeof(t_textures) * FRM);
	if (!gd->sprts->txtr)
		print_error(gd, 2);
	i = 0;
	while (i < FRM)
	{
		gd->sprts->txtr[i].ptr = NULL;
		gd->sprts->txtr[i++].path = NULL;
	}
	gd->sprts->fire = false;
	gd->sprts->frm = 0;
	init_sprites(gd);
	if (FRM <= 0)
		print_error(gd, 9);
}

void	free_sprites(t_gamedata *gd)
{
	int	i;

	i = 0;
	if (gd->sprts)
	{
		while (i < FRM)
		{
			if (gd->sprts->txtr[i].path)
				free(gd->sprts->txtr[i].path);
			if (gd->sprts->txtr[i].ptr)
				mlx_destroy_image(gd->mlx, gd->sprts->txtr[i].ptr);
			i++;
		}
		if (gd->sprts->txtr)
			free(gd->sprts->txtr);
		if (gd->sprts)
			free(gd->sprts);
	}
}

void	animate_sprite(t_gamedata *gd)
{
	int			f;
	t_vector	loc;

	if (gd->sprts->frm > 6)
	{
		gd->sprts->frm = 0;
		gd->sprts->fire = false;
	}
	f = gd->sprts->frm;
	loc.xi = ((gd->sprts->txtr[f].size.xi / 2)
			- (gd->sprts->txtr[f].size.xi - 150)) + (gd->size.xi / 2);
	loc.yi = gd->size.yi - gd->sprts->txtr[f].size.yi;
	mlx_put_image_to_window(gd->mlx, gd->win, gd->sprts->txtr[f].ptr,
		loc.xi, loc.yi);
}
