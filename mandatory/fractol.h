/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:03:57 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/19 07:35:42 by amousaid         ###   ########.fr       */
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

#define WIDTH 500
#define HEIGHT 500
#define ITR 40

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
	
}				t_ml;

// function part
int mandelbrot_do(double cr, double  ci);
void mandelbrot(t_ml param);
void	my_mlx_pixel_put(t_ml *data, int x, int y, int color);

// zoom part

int mouse_move(int botton, int x, int y,t_ml *param);
#endif