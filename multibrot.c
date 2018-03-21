/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:13:34 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/21 13:55:11 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	algo(t_context *f, double c_r, double c_i)
{
	int		iter;
	float	tmp;
	float	z_r;
	float	z_i;
	float	atanxy;

	z_r = 0;
	z_i = 0;
	iter = 0;

	while ((z_r * z_r) + (z_i * z_i) < 4 && iter < f->max_iter)
	{
		atanxy = atan2(z_i, z_r);
		tmp = pow(((z_r * z_r) + (z_i * z_i)), (f->d / 2)) * cos(f->d * atanxy) + c_r;
		z_i = pow(((z_r * z_r) + (z_i * z_i)), (f->d / 2)) * sin(f->d * atanxy) + c_i;
		z_r = tmp;
		iter++;
	}
	return (iter);
}

void		multibrot(t_context *f)
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
			ft_put_pixel(f->p.img.data_img, x, y, &f->p);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->p.mlx, f->p.win, f->p.img.img, 0, 0);
}
