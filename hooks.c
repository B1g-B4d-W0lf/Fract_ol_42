/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:18:04 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/12 19:44:42 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	closed(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_destroy(vars);
	if (keycode >= 49 || keycode <= 51)
		rainbow(keycode, vars);
	return (0);
}

int	cross(t_vars *vars)
{
	ft_destroy(vars);
	return (0);
}

int	mousezoom(int scroll, int x, int y, t_vars *vars)
{
	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	if (scroll == 4)
	{	
		vars->resize = vars->resize / 1.1;
		zooming(vars);
		if (vars->fract == MANDEL)
			make_mandel(vars);
		if (vars->fract == JULIA)
			make_julia(vars);
	}
	if (scroll == 5)
	{
		vars->resize = vars->resize * 1.1;
		zooming(vars);
		if (vars->fract == MANDEL)
			make_mandel(vars);
		if (vars->fract == JULIA)
			make_julia(vars);
	}
	return (0);
}

void	management(t_vars *vars)
{
	mlx_mouse_hook(vars->win, mousezoom, vars);
	mlx_hook(vars->win, 2, 1L << 0, closed, vars);
	mlx_hook(vars->win, 17, 1L << 17, cross, vars);
}
