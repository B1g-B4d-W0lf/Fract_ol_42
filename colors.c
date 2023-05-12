/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:37:22 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/12 00:32:56 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	rainbow(int keycode, t_vars *vars)
{
	if (keycode == 49)
		vars->color = 1;
	else if (keycode == 50)
		vars->color = 2;
	else if (keycode == 51)
		vars->color = 3;
	if (vars->fract == JULIA)
		make_julia(vars);
	else if (vars->fract == MANDEL)
		make_mandel(vars);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	trgb_creator( float n, t_vars vars)
{
	t_colors	ints;

	ints.t = 0;
	n = n / NMAX;
	if (vars.color == 1)
	{
		ints.r = 9.0 * (1 - n) * pow(n, 3) * 255.0;
		ints.g = 15.0 * pow((1 - n), 2) * pow(n, 2) * 255.0;
		ints.b = 8.5 * pow((1 - n), 3) * n * 255.0;
	}
	if (vars.color == 2)
	{
		ints.r = 9.0 * (1 - n) * pow(n, 3) * 255.0;
		ints.g = 8.5 * pow((1 - n), 3) * n * 255.0;
		ints.b = 15.0 * pow((1 - n), 2) * pow(n, 2) * 255.0;
	}
	if (vars.color == 3)
	{
		ints.r = 15.0 * pow((1 - n), 2) * pow(n, 2) * 255.0 + 70;
		ints.g = 9.0 * (1 - n) * pow(n, 3) * 255.0 + 20;
		ints.b = 8.5 * pow((1 - n), 3) * n * 255.0 + 2 ;
	}
	return (((int)ints.r << 16) | ((int)ints.g << 8) | ((int)ints.b));
}
