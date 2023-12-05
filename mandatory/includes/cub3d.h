/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:12:41 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/21 10:56:09 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
	REMOVE STDIO
*/
# include <stdio.h>

# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "../../includes/pixel_utils.h"
# include "../../libft/libft.h"
# include "../../libft/ft_printf/includes/ft_printf.h"
# include "../../libft/get_next_line/get_next_line.h"

# define WIDTH 1600
# define HEIGHT 1200
# define EXT ".cub"
# define TXTRS 4
# define FOV 60.0
# define SPEED .25
# define ROTATION 0.10
# define PGFX "./assets/pause.xpm"
# define FRM 7
# define LIGHT_EFFECT 5

/**
 * Mouse Move
 *  MOUSE = Enable or disable mouse
 *  MOUSE_HYST = Mouse Hysteresis (Deadband) around center
*/
# define MOUSE 1
# define MOUSE_HYST 5

/**
 * DEBUG MESSAGE
 *  DM = Number of Debug message stores (ie number of available messages)
*/
# define DEBUG 1
# define DM 20

/* OSX Keycodes */
# ifdef OSX
#  include "../../minilibx/mlx.h"
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_M 46
#  define KEY_P 35
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_SPACE 49
#  define KEY_RETURN 36
#  define KEY_L_SHIFT 257
#  define KEY_TILDE 50
# endif

/* Linux Keycodes */
# ifdef LINUX
#  include "../../minilibx-linux/mlx.h"
#  include <valgrind/memcheck.h>
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_M 109
#  define KEY_P 112
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_SPACE 32
#  define KEY_RETURN 65293
#  define KEY_L_SHIFT 65505
#  define KEY_TILDE 96
# endif

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOTION_NOTIFY 6
# define ENTER_NOTIFY 7
# define LEAVE_NOTIFY 8
# define FOCUS_IN 9
# define FOCUS_OUT 10
# define KEYMAP_NOTIFY 11
# define EXPOSE 12
# define GRAPHICS_EXPOSE 13
# define NO_EXPOSE 14
# define VISIBILITY_NNOTIFY 15
# define CREATE_NOTIFY 16
# define DESTROY_NOTIFY 17
# define UNMAP_NOTIFY 18
# define MAP_NOTIFY 19
# define MAP_REQUEST 20
# define REPARENT_NOTIFY 21
# define CONFIGURE_NOTIFY 22
# define CONFIGURE_REQUEST 23
# define GRAVITY_NOTIFY 24
# define RESIZE_REQUEST 25
# define CIRCULLATE_NOTIFY 26
# define CIRCULATE_REQUEST 27
# define PROPERTY_NOTIFY 28
# define SELECTION_CLEAR 29
# define SELECTION_REQUEST 30
# define SELECTION_NOTIFY 31
# define COLORMAP_NOTIFY 32
# define CLIENT_MESSAGE 33
# define MAPPING_NOTIFY 34
# define GENERIC_EVENT 35
# define LAST_EVENT 36
# define NO_EVENT_MSK 0L
# define KEY_PRESS_MSK 0
# define KEY_RELEASE_MSK 1
# define BUTTON_PRESS_MSK 2
# define BUTTON_RELEASE_MSK 3
# define ENTER_WIN_MSK 4
# define LEAVE_WIN_MSK 5
# define POINT_MOTION_MSK 6
# define POINTER_MOTION_HINT_MSK 7
# define BUTTON1_MOTION_MSK 8
# define BUTTON2_MOTION_MSK 9
# define BUTTON3_MOTION_MSK 10
# define BUTTON4_MOTION_MSK 11
# define BUTTON5_MOTION_MSK 12
# define BUTTON_MOTION_MSK 13
# define KEYMAP_STATE_MSK 14
# define EXPOSURE_MSK 15
# define VISIBILITY_CHANGE_MSK 16
# define STRUCTURE_NOTIFY_MSK 17
# define RESIZE_REDIRECT_MSK 18
# define SUBSTRUCTURE_NOTIFY_MSK 19
# define SUBSTRUCTURE_REDIRECT_MSK 20
# define FOCUS_CHANGE_MSK 21
# define PROPERTY_CHANGE_MSK 22
# define COLOR_MAP_CHANGE_MSK 23
# define OWNER_GRAB_BUTTON_MSK 24

/**
 * Coordinate System
 * 		Y
 * 		|
 * 	X --+-------------> x increases
 * 		|(0, 0)
 * 		|
 * 		|
 * 		v
 * 		y increases
 *
 * Origin (0,0) top left of map
 *		  N
 * 		 270
 * 		  |
 *W 180	--+-- 0 E
 * 		  |
 * 		 90
 *        S
**/

/**
 * Texture Directions
 * NO = North Wall Texture
 * SO = South Wall Texture
 * EA = East Wall Texture
 * WE = West Wall Texture
 **/
typedef enum e_directionType
{
	NO,
	SO,
	EA,
	WE
}	t_dir;

/**
 * Player Direction
 * N, S, E & W
 **/
typedef enum e_playerdirType
{
	N=270,
	S=90,
	E=0,
	W=180
}	t_plyr_dir;

typedef enum e_side
{
	HORIZON,
	VERTICAL,
	EQUAL
}	t_side;

typedef enum e_sign
{
	POS,
	NEG,
	CONST
}	t_sign;

/**
 * Color Channels
 * R = Red
 * B = Blue
 * G = Green
 * A = Alpha
 **/
typedef enum e_colors
{
	R,
	G,
	B,
	A
}	t_colors;

/**
 * F = Floor
 * C = Ceiling
 **/
typedef enum e_fc
{
	F,
	C
}	t_fc;

/**
 * Entity Type inside map
 * Used with check_wall
 * Returns
 * 	Floor = 0, Wall = 1, Unknown = 2
 *  Unknown is outside the map
 *  Player position is considered a Floor
 **/
typedef enum e_m_entity
{
	Floor,
	Wall,
	Unknown
}	t_m_entity;

/**
 * txtr[4] = Textures based on direction
 * 	[0]NO
 *  [1]SO
 *  [2]EA
 *  [3]WE
 * fccolors[2] = Floor and ceiling colors
 * 	[0] = Floor
 * 	[1] = Ceiling
 * **map = 2d map data
 **/
typedef struct s_mapdata
{
	t_textures	txtr[4];
	int			fccolors[2][3];
	char		**map;
	int			map_row;
	int			map_col;
	t_bool		light_eff;
	t_bool		elements_valid;
}	t_mapdata;

/**
 * Minimap Partial Blocks
 * Holds left, right, top, & bottom
 * block sizes for printing the minimap
 **/
typedef struct s_mmos
{
	double	lblkx;
	double	rblkx;
	double	tblky;
	double	bblky;
}	t_mmos;

/**
 * Minimap Data Structure
 *
 * *img = Image to hold mini map
 * size = Size of minimap
 * win_loc = Location to place minimap
 * active = show or hide minimap
 **/
typedef struct s_minimap
{
	t_textures	*img;
	t_vector	size;
	t_vector	win_loc;
	t_bool		active;
}	t_minimap;

/**
 * Wall Detection Structure
 * *vec = array of detection point (45 deg x8 from pov) by double x y
 * 	vec[0] is at dir of pov,
 * 	vec[1] is 45 deg to right
 * 	vec[2] is 45 deg of vec[1]...
 * hit = double x y of hit location
 * hit_seg = segment that got the hit as from dir[4][3]
 * dir[4][3] = Array of segemts
 * 	[0]{7, 0, 1} [1]{3, 4, 5} [2]{1, 2, 3} [3]{5, 6, 7}
 *
 *         0
 * 		   .
 * 	 7	 .	 .  1
 *  6   .  p  .   2
 *   5   .   .   3
 *         .
 *         4
 *
 * dir 1=S, 0=W, 2=D, 3=A
 **/
typedef struct s_detect
{
	t_vector	*vec;
	t_vector	hit;
	int			hit_seg;
	int			dir[4][3];
}	t_detect;

/**
 * Player Data
 * t_plyr_dir startdir = direction of start position N, S, E, or W
 * t_vector location = Current plaayer location as double (xd, yd)
 * t_dtect *det = Pointer to detection structure
 * t_vector mouse = mouse x y coordinates
 * double pov = Direction Player is facing in radians
 *
**/
typedef struct s_plyrdata
{
	t_plyr_dir	startdir;
	t_vector	location;
	t_detect	*det;
	t_vector	mouse;
	double		pov;
}	t_plyrdata;

/**
 * Full map structure
 * *img = Image pointer
 * size = full map size
 * win_loc = Location to put image in window
 * active = Whether to display the full map
 **/
typedef struct s_map
{
	t_vector	size;
	t_bool		active;
}	t_map;

typedef struct s_project
{
	double		wall_len;
	t_vector	w_coor;
}	t_project;

typedef struct s_raycast
{
	t_project	p_rc;
	t_vector	delta;
	t_vector	dist;
	t_vector	off_set;
	t_vector	ray_ang;
	t_sign		dir_x;
	t_sign		dir_y;
	t_side		side;
	double		theta;
	double		angle;
	double		og_dist;
}	t_raycast;

/**
 * Pause Structure
 *  t_textures p = Holds the Pause Image Asset
 *  t_bool hault = Pause Toggle
 **/
typedef struct s_pause
{
	t_textures	p;
	t_bool		hault;
}	t_pause;

typedef struct s_sprt
{
	t_textures	*txtr;
	int			frm;
	t_bool		fire;
}	t_sprt;

/**
 * Debug Console Structure
 *  char **str = Array of debug messages (store)
 *  int *color = Array of colors linked to **str
 *  size_t n = Number of Debug Messages that can be
 * 		accepted in the store (store size)
 **/
typedef struct s_debug
{
	char	**str;
	int		*color;
	t_bool	lock;
	size_t	n;
}	t_debug;

typedef struct s_mini_ray
{
	double		theta;
	t_vector	plot;
	t_vector	offset;
}	t_mini_ray;

/**
 * Game Data Structure
 * *mpd = Points to map data structure
 * *pd = Points to player data structure
 * *mm = Points to minimap data structure
 * *mlx = MLX Library Pointer
 * *win = MLX Window Pointer
 * *map = Points to the Full Size Map Structure
 * *pause = Points to the Pause Struture
 * dbg = Debug Console Structure
 * fb[2] = Frame Buffer, 2 images
 * 	1 for drawing and 1 for display
 * size = MLX Window Size
 **/
typedef struct s_gamedata
{
	void			*mlx;
	void			*win;
	t_mapdata		*mpd;
	t_plyrdata		*pd;
	t_minimap		*mm;
	t_map			*map;
	t_pause			*pause;
	t_sprt			*sprts;
	t_raycast		rc;
	t_mini_ray		m_ray;
	t_debug			dbg;
	t_frmbuf		fb;
	t_vector		size;
	size_t			framenum;
}	t_gamedata;

/*
*	Graphics Drawing
*/
void		drawfloorceiling(t_gamedata *gd);
void		drawcrosshair(t_gamedata *gd);
void		redraw(t_gamedata *gd);

/*
*	Utility Functions
*/
double		clamp(double in, double llimit, double hlimit);
t_vector	pol_cart(t_vector xy, double theta, double distance);

/*
*	Debug Console Functions
*/
void		debug(t_gamedata *gd);
void		debug_init(t_gamedata *gd);
void		c_log(t_gamedata *gd, char *str, int color, t_bool pause);

/*
*	Memory Management
*/
void		allocate(t_gamedata *gd);
void		free_memory(t_gamedata *gd);
void		print_error(t_gamedata *gd, int error);

/*
*	MLX Events
*/
int			keypress_evt(int keycode, t_gamedata *gd);
int			mouse_evt(int x, int y, t_gamedata *gd);
int			mouse_press_evt(int button, int x, int y, t_gamedata *gd);
int			windestroy_evt(t_gamedata *gd);
int			loop(t_gamedata *gd);

/*
*	MLX Mouse Wrappers
*/
int			mouse_move(t_gamedata *gd, int x, int y);
int			mouse_get_pos(t_gamedata *gd, int *x, int *y);
void		mouse_show(t_gamedata *gd);
void		mouse_hide(t_gamedata *gd);

/*
*  Mouse movement and Pause Screen
*/
void		alloc_pause(t_gamedata *gd);
void		free_pause(t_gamedata *gd);
void		print_pause(t_gamedata *gd);
void		mouse_move_plyr(t_gamedata *gd, int x, int y);
void		mouse_recenter(t_gamedata *gd, int x, int y);

/*
*	Parsing Config Files
*/
void		parse_validate_file(int fd, t_gamedata *gd);
int			parse_textures(char *buffer, t_gamedata *gd);
int			parse_colors(char *buffer, t_gamedata *gd);
int			parse_map(char *buffer, t_gamedata *gd);
int			validate_map(t_gamedata *gd);

/*
*	Wall Collision
*/
t_bool		wall_collision(t_gamedata *gd, int seg);
void		allocdetect(t_gamedata *gd);
void		freedetect(t_gamedata *gd);
void		initdetect(t_plyrdata *pd);
void		printdetect(t_gamedata *gd);

/*
*	Mini Map
*/
void		mini_map_init(t_gamedata *gd);
void		make_minimap(t_gamedata *gd);
void		put_player(t_gamedata *gd);
t_m_entity	check_wall(t_gamedata *gd, t_vector xy);

/*
*	Full Map Display
*/
void		map_init(t_gamedata *gd);
void		make_map(t_gamedata *gd);
void		map_put_player(t_gamedata *gd, t_vector xy, int color);
t_vector	map_calc(t_vector xy, t_gamedata *gd);

/*
*	Graphic Sprites
*/
void		alloc_sprites(t_gamedata *gd);
void		free_sprites(t_gamedata *gd);
void		animate_sprite(t_gamedata *gd);

/*
* Alka's Super Ray Caster
*/
t_vector	v_ray(t_gamedata gd, t_raycast rc);
void		new_plot(t_vector vec, t_gamedata gd);
t_vector	h_ray(t_gamedata gd, t_raycast rc);
void		plot_line(t_gamedata *gd);
void		ray_cast(t_gamedata *gd);
void		minimap_rays(t_gamedata *gd);

void		wall_check(t_gamedata *gd);
void		dir_plyer(t_gamedata *gd);
void		draw_3d(t_gamedata *gd, int ray_num);
void		set_3d_val(t_gamedata *gd);
double		dist_wall(t_gamedata *gd);

/*
* Texture Mapping
*/
t_dir		wtext(t_vector rloc, double theta);
void		put_texel(t_gamedata *gd, t_dir dir, double intensity);

#endif
