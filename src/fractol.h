/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:03:57 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/22 04:21:40 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define PLUS_KEY 65451
# define MAINIS_KEY 65453
# define KEY_1 38
# define KEY_2 233
# define KEY_3 34
# define KEY_4 39

// struct part
typedef struct s_ml
{
	// mlx
	void	*mlx;
	void	*win;
	// img
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	// comp
	double	r;
	double	i;
	// zoom
	double	zoom;
	// shift
	double	plus_x;
	double	plus_y;
	double	mainis_x;
	double	mainis_y;
	// rander
	double	itr;
	// colors
	int		shift;
	// julia x-y
	double	julia_x;
	double	julia_y;
	// type
	char	type;
}			t_ml;

// function part
void		mandelbrot(t_ml param);
void		julia(t_ml fractol);
void burning_ship(t_ml fractol);
void		my_mlx_pixel_put(t_ml *data, int x, int y, int color);
int			check_arg(char *s);
// hook part
int			close_all(t_ml *param);
int			keycheck(int keycode, t_ml *param);
void		hook(t_ml *fractol);

// zoom part
int			mouse_move(int botton, int x, int y, t_ml *param);

// error part
void		is_error(void);
#endif