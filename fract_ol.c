/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:26:56 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/12 02:32:50 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	consignes(void)
{
	ft_printf("Hey that ain't how it works !\n");
	ft_printf("For Mandelbrot you can simply type 1.\n");
	ft_printf("For Julia you gotta type 2, followed by valid coordinates.\n");
	ft_printf("I believe that's about all, enjoy :) !\n");
	exit(0);
}

void	ft_destroy(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	zooming(t_vars *vars)
{
	vars->imsize = vars->resize;
	vars->re = vars->resize / 2;
	vars->im = vars->re;
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.resize = 4.000;
	vars.color = 1;
	if (argc == 2 && ft_atoi(argv[1]) == MANDEL)
	{
		vars.fract = atoi(argv[1]);
		zooming(&vars);
		make_mandel_win(&vars);
	}
	else if (argc == 4 && ft_atoi(argv[1]) == JULIA)
	{
		vars.fract = atoi(argv[1]);
		vars.c.re = ft_atof(argv[2]);
		vars.c.im = ft_atof(argv[3]);
		zooming(&vars);
		make_julia_win(&vars);
	}
	else if (argc == 1)
	{
		make_sierpinski_win(&vars);
	}
	else
		consignes();
	return (0);
}
