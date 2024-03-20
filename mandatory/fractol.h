/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:03:57 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/20 04:58:05 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libft/libft.h"
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"
#include <stdio.h>
#include <X11/keysym.h> 
#include <X11/X.h> 

#define WIDTH 800
#define HEIGHT 800
#define PLUS_KEY 65451
#define MAINIS_KEY 65453
#define KEY_1 38
#define KEY_2 233
#define KEY_3 34
#define KEY_4 39


// struct part
typedef struct	s_ml {
	//mlx
	void	*mlx;
	void	*win;
	//img
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	//comp
	double r;
    double i;
	//zoom
	double zoom;
	//shift
	double plus_x;
	double plus_y;
	double mainis_x;
	double mainis_y;
	//rander
	double itr;
	//colors
	int shift;
}				t_ml;

// function part
int mandelbrot_do(double cr, double  ci, int itr);
void mandelbrot(t_ml param);
void	my_mlx_pixel_put(t_ml *data, int x, int y, int color);

// hook part
int	close_all(t_ml *param);
int keycheck(int keycode, t_ml *param);
void hook(t_ml *fractol);

// zoom part
int mouse_move(int botton, int x, int y,t_ml *param);

#endif