/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:42:10 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/14 16:45:50 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fractals(t_context *f)
{
	if (f->name == 0)
		mandelbrot(f);
	if (f->name == 1)
		julia(f);
	if (f->name == 2)
		burning_ship(f);
	if (f->name == 3)
		sierpinski(f);	
}
