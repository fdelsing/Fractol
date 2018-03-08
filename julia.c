/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:50:10 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/08 17:57:51 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	travel_map_jul(t_context *f)
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
			c_r = (x - /*f->p.c_x + */(WIN_X - f->m_x)) * f->ratio * f->zoom;
			c_i = (y - /*f->p.c_y + */(WIN_Y - f->m_y)) * f->ratio * f->zoom;
			f->p.img.color = julia(f, c_r, c_i) * 0x0000ff / f->max_iter;
			ft_put_pixel(f->p.img.data_img, x, y, &f->p);
	//	if (julia(f, c_r, c_i) == f->max_iter + 1)
			//		ft_put_pixel(f->p.img.data_img, x, y, &f->p);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->p.mlx, f->p.win, f->p.img.img, 0, 0);
}

int		julia(t_context *f, double c_r, double c_i)
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