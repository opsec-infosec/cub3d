/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:22:06 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 19:26:35 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_console_dump(t_gamedata *gd)
{
	int	i;

	printf("------------ Console Dump ------------\n");
	if (gd->dbg.str && gd->dbg.color)
	{
		i = -1;
		while (++i < DM && gd->dbg.str[i])
			printf("%d: %s\n", i, gd->dbg.str[i]);
	}
	printf("--------------------------------------\n\n");
}

/**
 * Print Error Messages
 * Free Memory
 * Exit Program
*/
void	print_error(t_gamedata *gd, int error)
{
	static char	serror[10][50] = {
		"Invalid Number of Arguments\n",
		"Map File Not Found\n",
		"Cannot Allocate Memory!\n",
		"MLX Library Init Failure\n",
		"Door configuration in map is invalid\n",
		"Map is not enclosed by walls\n",
		"Too many or No player located in map\n",
		"Map Extension Invalid\n",
		"Map Config File Invalid\n",
		"Texture Asset File Not Found\n"};

	ft_printf("\aError\a\n");
	ft_printf("\a%s\n", serror[error]);
	if (DEBUG)
		print_console_dump(gd);
	free_memory(gd);
	exit (EXIT_FAILURE);
}
