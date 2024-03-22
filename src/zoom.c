/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:23:21 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/21 20:59:19 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int botton, int x, int y, t_ml *fractol)
{
	(void)x;
	(void)y;
	if (botton == 4)
		fractol->zoom *= 0.95;
	if (botton == 5)
		fractol->zoom *= 1.05;
	if (fractol->type == 'm')
		mandelbrot(*fractol);
	else if (fractol->type == 'j')
		julia(*fractol);
	return (0);
}
