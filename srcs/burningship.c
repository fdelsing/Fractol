/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:44:33 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 16:06:16 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		burning_ship(t_context *f, double c_r, double c_i)
{
	int		iter;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = 0;
	z_i = 0;
	iter = 0;
	while ((z_r * z_r) + (z_i * z_i) < 4 && iter < f->max_iter)
	{
		tmp = z_r;
		z_r = fabs((z_r * z_r) - (z_i * z_i) + c_r);
		z_i = fabs(2 * tmp * z_i + c_i);
		iter++;
	}
	return (iter);
}
