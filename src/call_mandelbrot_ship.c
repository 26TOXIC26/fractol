/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_mandelbrot_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:15:37 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/23 00:26:46 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call_mandelbrot_ship(t_ml *fractol, char *type)
{
	fractol->type = type[0];
	get_mlx(fractol);
	data_insialize(fractol, 0, 0);
	if (type[0] == 'm')
		mandelbrot(*fractol);
	else
		burning_ship(*fractol);
	hook(fractol);
	mlx_loop(fractol->mlx);
}
