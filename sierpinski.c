/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:01:00 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/13 23:09:10 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	algo(t_context *f, double x, double y)
{
	int		iter;
	float	size;

	size = 1;
	iter = 0;
	while ((((fabs(x) <= size) || fabs(x) >= size * 2)  &&
				(fabs(y) <= size || fabs(y) >= size * 2))
				&& iter <= f->max_iter)
	{
		iter++;
		size = size / 2;
	}
//	printf("iter = %d\n", iter);
//	printf("x = %f y = %f\n", x, y);
	return (iter);
}

void		sierpinski(t_context *f)
{
	int		x;
	int		y;
	double	valx;
	double	valy;

	x = 0;
	while (x <= WIN_X)
	{
		y = 0;
		while (y <= WIN_Y)
		{
		//	printf("ratio = %f\n", f->ratio);
			f->p.img.color = 0x0000ff;
			valx = (x - f->p.c_x) * f->ratio;
			valy = (y - f->p.c_y) * f->ratio;
			f->p.img.color = algo(f, valx, valy) * 0xffffff / f->max_iter;
			ft_put_pixel(f->p.img.data_img, x, y, &f->p);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->p.mlx, f->p.win, f->p.img.img, 0, 0);
}
