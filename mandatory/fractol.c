/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:38:13 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/19 02:24:58 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_ml *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_all(t_ml *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}
int keycheck(int keycode, t_ml *param)
{
	if (keycode == XK_Escape)
		close_all(param);
	else if (keycode == XK_Up)
	{
		
	}
	
	return (0);
}

void hook(t_ml fractol)
{
	mlx_mouse_hook(fractol.win, mouse_move, &fractol);
	mlx_hook(fractol.win, KeyPress, KeyPressMask, keycheck, &fractol);
	mlx_hook(fractol.win, DestroyNotify, StructureNotifyMask, close_all, &fractol);
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
	mandelbrot(fractol);
	hook(fractol);
	mlx_loop(fractol.mlx);
}
