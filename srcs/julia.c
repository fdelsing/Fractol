/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:50:10 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/11 17:33:33 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(t_context *f, double c_r, double c_i)
{
	int		iter;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = c_r;
	z_i = c_i;
	c_r = ((f->m_x - f->p.c_x) * f->ratio);
	c_i = ((f->m_y - f->p.c_y) * f->ratio);
	iter = 0;
	while ((z_r * z_r) + (z_i * z_i) < 4 && iter < f->max_iter)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = 2 * tmp * z_i + c_i;
		iter++;
	}
	return (iter);
}
