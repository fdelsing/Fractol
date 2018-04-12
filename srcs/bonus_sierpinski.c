/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:01:00 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 16:05:44 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		sierpinski(t_context *f, double c_r, double c_i)
{
	int		iter;
	int		size;

	iter = 0;
	size = 3;
	c_r = fabs(c_r);
	c_i = fabs(c_i);
	while ((((int)c_r % size != 1) || (int)c_i % size != 1)
			&& iter <= f->max_iter)
	{
		iter++;
		c_r *= 3;
		c_i *= 3;
	}
	return (iter);
}
