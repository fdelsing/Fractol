/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bacteria.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:46:20 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/11 17:33:41 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

#define ABS(value) (((value) < 0) ? -((value)) : (value))

int		bacteria(t_context *f, double c_r, double c_i)
{
	int		iter;
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	iter = 0;
	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = (c_i + c_i) * c_r + ((f->m_y - f->p.c_y) * f->ratio);
	z_r = z_r_c - z_i_c + ((f->m_x - f->p.c_x) * f->ratio);
	while (z_r_c + z_i_c <= 4 && iter < f->max_iter)
	{
		z_r_c = z_r * z_r - ((double)(iter % 3));
		z_i_c = z_i * z_i;
		z_i = (z_i + z_i) * z_r + ((f->m_y - f->p.c_y) * f->ratio);
		z_r = ABS(z_r_c - z_i_c + ((f->m_x - f->p.c_x) * f->ratio));
		iter++;
	}
	return (iter);
}
