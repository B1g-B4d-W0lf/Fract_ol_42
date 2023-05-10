/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:26:56 by wfreulon          #+#    #+#             */
/*   Updated: 2023/05/11 00:22:37 by wfreulon         ###   ########.fr       */
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

float	ft_atof(char *str)
{
	int		i;
	float	f[4];

	f[3] = 0.1;
	f[1] = 0.;
	f[0] = 0;
	f[2] = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f[2] = f[2] * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		f[0] = f[0] * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			f[1] = f[1] + (str[i] - 48) * f[3];
			f[3] = f[3] * 0.1;
			i++;
		}
	}
	f[0] = (f[0] + f[1]) * f[2];
	return (f[0]);
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
	float	c;

	vars.resize = 4.000;
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
	else
		consignes();
	return (0);
}
