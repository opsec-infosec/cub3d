/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:40:25 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/19 00:56:57 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

double	clamp(double in, double llimit, double hlimit)
{
	if (in >= hlimit)
		return (llimit);
	if (in < llimit)
		return (hlimit - ROTATION);
	return (in);
}

/**
 * Calculate number of x or y moves
 * 	Convert from Polar to Cartesian
 * 	Known:
 * 		theta = angle from 0 degrees (E)
 * 		distance = speed of movement
 *
 * 	x = distance x cos(theta)
 *  y = distance x sin(theta)
 *
 *  added to the original x,y
 * 	gives nex x,y coords
 *
 * https://www.mathsisfun.com/polar-cartesian-coordinates.html
 *
 **/

t_vector	pol_cart(t_vector xy, double theta, double distance)
{
	t_vector	vec;

	vec.xd = 0;
	vec.yd = 0;
	vec.xd = (cos(theta) * distance) + xy.xd;
	vec.yd = (sin(theta) * distance) + xy.yd;
	if (vec.xd < 1.0)
		vec.xd = 1.0;
	if (vec.yd < 1.0)
		vec.yd = 1.0;
	return (vec);
}
