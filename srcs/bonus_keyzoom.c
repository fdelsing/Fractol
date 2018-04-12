/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_keyzoom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:23:34 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/11 16:14:32 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		zoom(int keycode, t_context *f)
{
	double	zm_sp;

	zm_sp = 1.2;
	if (keycode == 27)
	{
		f->zoom *= zm_sp;
		f->zoomx += (double)(f->m_x - f->p.c_x) * f->ratio *
			(f->zoom * (1 / zm_sp - 1));
		f->zoomy += (double)(f->m_y - f->p.c_y) * f->ratio *
			(f->zoom * (1 / zm_sp - 1));
	}
	if (keycode == 24)
	{
		f->zoom /= zm_sp;
		f->zoomx += (double)(f->m_x - f->p.c_x) * f->ratio *
			(f->zoom * (zm_sp - 1));
		f->zoomy += (double)(f->m_y - f->p.c_y) * f->ratio *
			(f->zoom * (zm_sp - 1));
	}
	return (0);
}
