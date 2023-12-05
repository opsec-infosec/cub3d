/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:56:08 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/06 22:41:45 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_UTILS_H
# define PIXEL_UTILS_H

# include <stdint.h>
# include "../libft/libft.h"

# define RED_MSK 0xFF0000
# define GREEN_MSK 0xFF00
# define BLUE_MSK 0xFF

# ifdef OSX
#  include "../minilibx/mlx.h"
# endif

# ifdef LINUX
#  include "../minilibx-linux/mlx.h"
# endif

/**
 * Texture Maps
 * *path = Path of asset xpm file
 * *ptr = Pointer to image file
 * *addr = Texture Map Address
 * bbp = bits per pixel
 * lsize = Line Size
 * endian = endian of pixel colors
 * size = width x height
 **/
typedef struct s_textures
{
	char		*path;
	void		*ptr;
	char		*addr;
	int			bpp;
	int			lsize;
	int			endian;
	t_vector	size;
}	t_textures;

/**
 * Frame Buffers
 **/
typedef struct s_framebuffer
{
	void		*mlx;
	void		*win;
	t_textures	img[2];
	int			inactive;
}	t_frmbuf;

int		rgb_to_int(uint8_t red, uint8_t green, uint8_t blue);
void	int_to_rgb(int color, uint8_t *red, uint8_t *green, uint8_t *blue);
void	put_pixel_fb(t_frmbuf *fb, t_vector xy, int color);
void	put_pixel(t_textures *img, t_vector xy, int color);
int		get_pixel(t_textures txtr, t_vector xy);
int		allocate_img_buffer(void *mlx, void *win, t_frmbuf *fb, t_vector size);
int		put_img_to_window(t_frmbuf *fb);
void	put_img_to_fb(t_textures *img, t_frmbuf fb, t_vector loc);
void	free_img_buffer(t_frmbuf *fb);

#endif
