/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:23:21 by amousaid          #+#    #+#             */
/*   Updated: 2024/03/19 01:38:07 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_move(int botton, int x, int y, t_ml *fractol)
{
    if (botton == 4)
        fractol->zoom *= 0.95;
    if (botton == 5)
        fractol->zoom *= 1.05;
    mandelbrot(*fractol);
    return (0);
}