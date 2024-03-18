/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:03:57 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/18 06:31:02 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../libft/libft.h"
#include <stdlib.h>
#include "../minilibx/mlx.h"
#include <stdio.h>

#define WIDTH 500
#define HEIGHT 500

// struct part
typedef struct          s_comp
{
    double r;
    double i;
}                       t_comp;

typedef struct	s_ml {
	void	*mlx;
	void	*win;
}				t_ml;
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// function part
int mandelbrot_do(double cr, double  ci);
void mandelbrot(t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif