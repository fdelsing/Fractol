/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:50:10 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/15 23:49:44 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	algo(t_context *f, double c_r, double c_i)
{
	int		iter;
	float	tmp;
	float	z_r;
	float	z_i;

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

void	julia(t_context *f)
{
	int		x;
	int		y;
	double	c_r;
	double	c_i;

	x = 0;
	while (x <= WIN_X)
	{
		y = 0;
		while (y <= WIN_Y)
		{
			c_r = (x - f->p.c_x) * f->ratio;// * f->zoom;
			c_i = (y - f->p.c_y) * f->ratio;// * f->zoom;
			
			color(algo(f, c_r, c_i), f);
			//f->p.img.color.hex = color(algo(f, c_r, c_i), f);
			ft_put_pixel(f->p.img.data_img, x, y, &f->p);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->p.mlx, f->p.win, f->p.img.img, 0, 0);
}
