/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:13:34 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 16:06:00 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		multibrot(t_context *f, double c_r, double c_i)
{
	int		iter;
	double	tmp;
	double	z_r;
	double	z_i;
	double	atanxy;

	z_r = 0;
	z_i = 0;
	iter = 0;
	while ((z_r * z_r) + (z_i * z_i) < 4 && iter < f->max_iter)
	{
		atanxy = atan2(z_i, z_r);
		tmp = pow(((z_r * z_r) + (z_i * z_i)), (f->d / 2)) *
			cos(f->d * atanxy) + c_r;
		z_i = pow(((z_r * z_r) + (z_i * z_i)), (f->d / 2)) *
			sin(f->d * atanxy) + c_i;
		z_r = tmp;
		iter++;
	}
	return (iter);
}
