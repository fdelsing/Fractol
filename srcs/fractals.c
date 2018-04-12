/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:42:10 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 16:21:04 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void		fractals(t_context *f, double c_r, double c_i)
{
	if (f->name == 0)
		color(mandelbrot(f, c_r, c_i), f);
	if (f->name == 1)
		color(julia(f, c_r, c_i), f);
	if (f->name == 2)
		color(burning_ship(f, c_r, c_i), f);
	if (f->name == 3)
		color(sierpinski(f, c_r, c_i), f);
	if (f->name == 4)
		color(multibrot(f, c_r, c_i), f);
	if (f->name == 5)
		color(bacteria(f, c_r, c_i), f);
	if (f->name == 6)
		color(tricorn(f, c_r, c_i), f);
}

void			travel_map(t_context *f)
{
	int		x;
	int		y;
	double	c_r;
	double	c_i;

	x = 0;
	while (x <= WIN_X)
	{
		c_r = (double)(x - f->p.c_x) * f->ratio * f->zoom + f->zoomx;
		y = 0;
		while (y <= WIN_Y)
		{
			c_i = (double)(y - f->p.c_y) * f->ratio * f->zoom + f->zoomy;
			fractals(f, c_r, c_i);
			ft_put_pixel(f->p.img.data_img, x, y, &f->p);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->p.mlx, f->p.win, f->p.img.img, 0, 0);
}

static void		palette2(int iter, double ratio, t_context *f)
{
	f->p.img.color.rgba.r = (int)((1 - ratio * 10) * 0xff) % 255;
	f->p.img.color.rgba.g = (ratio) * 0xff;
	f->p.img.color.rgba.b = (1 - ratio) * 0xff;
	if (iter % 3 == 0)
		f->p.img.color.rgba.b = (iter / f->max_iter) * 0xff;
	if (iter % 3 == 1)
		f->p.img.color.rgba.g = iter * 0xff / f->max_iter;
	if (iter % 3 == 2)
		f->p.img.color.rgba.r = iter * 0xff / f->max_iter;
}

void			color(int iter, t_context *f)
{
	double	ratio;

	ratio = (float)iter / (float)f->max_iter;
	f->p.img.color.hex = 0x000000;
	if (f->palette == 0)
		f->p.img.color.hex = iter * 0x0000ff / f->max_iter;
	if (f->palette == 1)
	{
		if (iter % 3 == 0)
			f->p.img.color.hex = (1 - ratio) * 0x8888ff;
		if (iter % 3 == 1)
			f->p.img.color.hex = (1 - ratio) * 0x88ff88;
		if (iter % 3 == 2)
			f->p.img.color.hex = (1 - ratio) * 0xff8888;
	}
	if (iter == f->max_iter)
		f->p.img.color.hex = 0x000000;
	if (f->palette == 2)
		palette2(iter, ratio, f);
}
