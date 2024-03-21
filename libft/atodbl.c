/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:10:13 by pc                #+#    #+#             */
/*   Updated: 2024/03/21 01:01:14 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double atodbl(char *s)
{
    long int_part;
    double double_part;
    int sign;
    double power;
    
    double_part = 0;
    int_part = 0;
    sign = 1;
    power = 1;
    while (*s == '+' || *s == '-')
    {
        if (*s == '-')
            sign *= -1;
        s++;
    }
    while (*s != '.' && *s)
        int_part = (int_part * 10) + (*s++ - 48);
    if (*s == '.')
        s++;
    while (*s)
    {
        power /= 10;
        double_part = double_part + (*s++ - 48) * power;
    }
    return ((int_part + double_part) * sign);
}
