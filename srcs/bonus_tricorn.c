/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tricorn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:50:44 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 16:05:21 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		tricorn(t_context *f, double c_r, double c_i)
{
	int		iter;
	double	z_r;
	double	z_i;
	double	z_r_c;
	double	z_i_c;

	iter = 0;
	z_r_c = c_r * c_r;
	z_i_c = c_i * c_i;
	z_i = -2 * c_r * c_i + c_i;
	z_r = z_r_c - z_i_c + c_r;
	while (z_r_c + z_i_c <= 4 && iter < f->max_iter)
	{
		z_r_c = z_r * z_r;
		z_i_c = z_i * z_i;
		z_i = -2 * z_r * z_i + c_i;
		z_r = z_r_c - z_i_c + c_r;
		iter++;
	}
	return (iter);
}
