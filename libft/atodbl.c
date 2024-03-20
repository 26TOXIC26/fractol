/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:10:13 by pc                #+#    #+#             */
/*   Updated: 2024/03/20 21:32:48 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double atodbl(char *s)
{
    long int_part;
    double double_part;
    int i;
    int sign;
    double power;
    
    double_part = 0;
    int_part = 0;
    i = 0;
    sign = 1;
    power = 1;
    while (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i] != '.' && s[i])
        int_part = (int_part * 10) + (s[i++] - 48);
    if (s[i] == '.')
        i++;
    while (s[i])
    {
        power /= 10;
        double_part = double_part + (s[i++] - 48) * power;
    }
    return ((int_part + double_part) * sign);
}