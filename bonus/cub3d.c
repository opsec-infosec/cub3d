/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:11:44 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 22:48:18 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/**
 * Check validity of file extension
 **/
static int	check_extension(char **arg)
{
	char	*tmp;

	tmp = ft_strrchr(arg[1], '.');
	if (!tmp || ft_strncmp(tmp, EXT, 5))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * MLX Loop Event
 **/
int	loop(t_gamedata *gd)
{
	clock_t	cur;
	clock_t	dif;

	if (!gd->pause->hault)
	{
		if (gd->framenum % 1000 == 0 && gd->sprts->fire)
			gd->sprts->frm++;
		if (gd->framenum % 500 == 0)
		{
			cur = clock();
			redraw(gd);
			dif = clock() - cur;
			if (dif > 0)
				gd->fps = (size_t)(CLOCKS_PER_SEC / dif);
		}
		gd->framenum++;
	}
	return (EXIT_SUCCESS);
}

/**
 * Initialize Windows Event Hooks
 * mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);
 **/
static void	hooks_init(t_gamedata *gd)
{
	c_log(gd, ft_strdup("Initialize Hooks..."), -1, true);
	mlx_hook(gd->win, KEY_PRESS, 1L << KEY_PRESS_MSK, &keypress_evt, gd);
	mlx_hook(gd->win, DESTROY_NOTIFY, NO_EVENT_MSK, &windestroy_evt, gd);
	if (MOUSE)
	{
		mlx_hook(gd->win, MOTION_NOTIFY, 1L << POINT_MOTION_MSK,
			&mouse_evt, gd);
		mlx_hook(gd->win, MOUSE_PRESS, 1L << BUTTON_PRESS_MSK,
			&mouse_press_evt, gd);
	}
	gd->framenum = 0;
	gd->fps = 0;
	mlx_loop_hook(gd->mlx, loop, gd);
}

int	main(int ac, char **av)
{
	t_gamedata	gd;

	ft_memset(&gd, 0, sizeof(t_gamedata));
	debug_init(&gd);
	if (ac != 2)
		print_error(&gd, 0);
	c_log(&gd, ft_strdup("Check Map Extension..."), -1, false);
	if (check_extension(av))
		print_error(&gd, 7);
	gd.size.xi = WIDTH;
	gd.size.yi = HEIGHT;
	gd.mlx = mlx_init();
	if (!gd.mlx)
		print_error(&gd, 3);
	gd.win = mlx_new_window(gd.mlx, gd.size.xi, gd.size.yi, "Cub3D");
	if (!gd.win)
		print_error(&gd, 3);
	allocate(&gd);
	c_log(&gd, ft_strdup("Parsing / Validating Map..."), -1, false);
	parse_validate_file(open(av[1], O_RDONLY), &gd);
	hooks_init(&gd);
	mlx_loop(gd.mlx);
	return (EXIT_SUCCESS);
}
