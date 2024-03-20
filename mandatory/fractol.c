/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/20 04:59:34 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_ml *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	t_ml fractol;

	fractol.mlx = mlx_init();

	
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Hello world!");
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bits_per_pixel, &fractol.line_length,
								&fractol.endian);
	fractol.zoom = 1;
	fractol.itr = 40;
	fractol.shift = 1;
	mandelbrot(fractol);
	hook(&fractol);
	mlx_loop(fractol.mlx);
}
