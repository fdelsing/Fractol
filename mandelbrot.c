/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:01:27 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/04 21:18:00 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mandelbrot(t_context *f, double c_r, double c_i)
{
	int		iter;
	float	tmp;
	float	z_r;
	float	z_i;

	z_r = 0;
	z_i = 0;
	iter = 0;
	while ((z_r * z_r) + (z_i * z_i) < 4 && iter <= f->max_iter)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = 2 * tmp * z_i + c_i;
		iter++;
	}
	return (iter);
}
