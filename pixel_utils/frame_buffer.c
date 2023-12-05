/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:59:59 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/06 19:49:45 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pixel_utils.h"

int	allocate_img_buffer(void *mlx, void *win, t_frmbuf *fb, t_vector size)
{
	int	i;

	i = 0;
	if (!mlx || !win)
		return (EXIT_FAILURE);
	fb->mlx = mlx;
	fb->win = win;
	while (i < 2)
	{
		fb->img[i].size.xi = size.xi;
		fb->img[i].size.yi = size.yi;
		if (fb->img[i].ptr)
			mlx_destroy_image(mlx, fb->img[i].ptr);
		fb->img[i].ptr = mlx_new_image(mlx, fb->img[i].size.xi,
				fb->img[i].size.yi);
		if (!fb->img[i].ptr)
			return (EXIT_FAILURE);
		fb->img[i].addr = mlx_get_data_addr(fb->img[i].ptr, &fb->img[i].bpp,
				&fb->img[i].lsize, &fb->img[i].endian);
		if (!fb->img[i].addr)
			return (EXIT_FAILURE);
		i++;
	}
	fb->inactive = 1;
	return (EXIT_SUCCESS);
}

void	put_img_to_fb(t_textures *img, t_frmbuf fb, t_vector loc)
{
	t_vector	xy;
	t_vector	tloc;

	if (!img)
		return ;
	if (loc.xi <= fb.img[fb.inactive].size.xi
		&& loc.yi <= fb.img[fb.inactive].size.yi)
	{
		xy.yi = 0;
		tloc.yi = loc.yi;
		while (xy.yi < img->size.yi)
		{
			xy.xi = 0;
			tloc.xi = loc.xi;
			while (xy.xi < img->size.xi)
			{
				put_pixel_fb(&fb, tloc, get_pixel(*img, xy));
				xy.xi++;
				tloc.xi++;
			}
			xy.yi++;
			tloc.yi++;
		}
	}
}

int	put_img_to_window(t_frmbuf *fb)
{
	t_textures	*b;
	int			fbia;
	void		*mlx;

	fb->inactive = !fb->inactive;
	fbia = fb->inactive;
	mlx = fb->mlx;
	b = &fb->img[fbia];
	mlx_put_image_to_window(mlx, fb->win, fb->img[!fbia].ptr, 0, 0);
	if (b->ptr && mlx)
		mlx_destroy_image(mlx, fb->img[fbia].ptr);
	b->ptr = mlx_new_image(mlx, b->size.xi, b->size.yi);
	if (!b->ptr)
		return (EXIT_FAILURE);
	b->addr = mlx_get_data_addr(b->ptr, &b->bpp, &b->lsize, &b->endian);
	if (!b->addr)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	free_img_buffer(t_frmbuf *fb)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (fb->img[i].ptr && fb->mlx)
			mlx_destroy_image(fb->mlx, fb->img[i].ptr);
		i++;
	}
}
