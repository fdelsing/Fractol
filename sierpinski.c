/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:01:00 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/21 15:20:17 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	algo(t_context *f, double x, double y)
{
	int		iter;
	int		size;

	iter = 0;
	size = 3;
	x = fabs(x);
	y = fabs(y);
	while ((((int)x % size != 1) || (int)y % size != 1)
		   	&& iter <= f->max_iter)
	{
		iter++;
		x *= 3;
		y *= 3;
	}
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
			//f->p.img.color = 0x0000ff;
			valx = (x - f->p.c_x) * f->zoom * f->ratio;
			valy = (y - f->p.c_y) * f->zoom * f->ratio;
			f->p.img.color.hex = algo(f, valx, valy) * 0x0000ff / f->max_iter;
			ft_put_pixel(f->p.img.data_img, x, y, &f->p);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->p.mlx, f->p.win, f->p.img.img, 0, 0);
}
