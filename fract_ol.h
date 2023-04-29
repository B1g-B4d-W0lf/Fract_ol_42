/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 02:27:12 by wfreulon          #+#    #+#             */
/*   Updated: 2023/04/29 02:54:08 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} ;

typedef struct s_colors
{
	int	t;
	int	r;
	int	g;
	int	b;
}			t_colors;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

# endif


