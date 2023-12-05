/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:07:47 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/13 12:49:11 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pixel_utils.h"

/**
 * rgb_to_int convert RGB to int
 * int *color = Returned converted int
 * red, green, blue = uint8 RGB Values
 **/
int	rgb_to_int(uint8_t red, uint8_t green, uint8_t blue)
{
	int	color;

	color = red << 16 | green << 8 | blue;
	return (color);
}

/**
 *  int_to_rgb Convert int values to RGB
 *  int color = int color value
 *  *red, *green *blue = Returned converted values to uint8
 **/
void	int_to_rgb(int color, uint8_t *red, uint8_t *green, uint8_t *blue)
{
	*red = ((color & RED_MSK) >> 16);
	*green = ((color & GREEN_MSK) >> 8);
	*blue = color & BLUE_MSK;
}

void	put_pixel(t_textures *img, t_vector xy, int color)
{
	int		i;
	char	*dst;

	i = img->bpp - 8;
	dst = img->addr + (xy.yi * img->lsize + xy.xi * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/**
 * put_pixel to inactive framebuffer
 * *fb = framebuffer
 * x = x location
 * y = y location
 * color = pixel color
 **/
void	put_pixel_fb(t_frmbuf *fb, t_vector xy, int color)
{
	t_textures		*b;

	b = &fb->img[fb->inactive];
	color = (unsigned int)((color & 0xFF000000) ^ color);
	put_pixel(b, xy, color);
}

/**
 * get_pixel from txtr
 * txtr = Texture img file
 * x = location x in img file
 * y = location y in img file
 * Returns color as int
 **/
int	get_pixel(t_textures txtr, t_vector xy)
{
	int		color;
	char	*pixel;

	pixel = txtr.addr + (xy.yi * txtr.lsize + xy.xi * (txtr.bpp / 8));
	color = *(int *)pixel;
	return (color);
}
