/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:24:50 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/23 00:03:42 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_all(t_ml *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}

int	key_do(t_ml param)
{
	if (param.type == 'm')
		mandelbrot(param);
	else if (param.type == 'j')
		julia(param);
	else if (param.type == 's')
		burning_ship(param);
	return (0);
}

int	keycheck(int keycode, t_ml *param)
{
	if (keycode == XK_Escape)
		close_all(param);
	else if (keycode == XK_Up)
		param->plus_y += (0.25 * param->zoom);
	else if (keycode == XK_Down)
		param->mainis_y -= (0.25 * param->zoom);
	else if (keycode == XK_Right)
		param->plus_x += (0.25 * param->zoom);
	else if (keycode == XK_Left)
		param->mainis_x -= (0.25 * param->zoom);
	else if (keycode == PLUS_KEY)
		param->itr *= 1.05;
	else if (keycode == MAINIS_KEY)
		param->itr *= 0.95;
	else if (keycode == KEY_1 && param->shift <= 16)
		param->shift++;
	else if (keycode == KEY_2 && param->shift > 0)
		param->shift--;
	else
		return (0);
	key_do(*param);
	return (0);
}

void	hook(t_ml *fractol)
{
	mlx_mouse_hook(fractol->win, mouse_move, fractol);
	mlx_hook(fractol->win, KeyPress, KeyPressMask, keycheck, fractol);
	mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, close_all,
		fractol);
}
