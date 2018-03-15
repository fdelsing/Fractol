/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:42:10 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/15 23:49:42 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fractals(t_context *f)
{
	if (f->name == 0)
		mandelbrot(f);
	if (f->name == 1)
		julia(f);
	if (f->name == 2)
		burning_ship(f);
	if (f->name == 3)
		sierpinski(f);
	if (f->name == 4)
		bla(f);
}

void	color(int iter, t_context *f)
{
	double	ratio;

	ratio = (float)iter / (float)f->max_iter;
	f->p.img.color.hex = 0x000000; 
	if (f->palette == 0)
		f->p.img.color.hex = iter * 0xff0000 / f->max_iter;
	if (f->palette == 1)
	{

//		f->p.img.color.rgba.r = (int)((1-ratio * 10) * 0xff) % 255 ; 
//		f->p.img.color.rgba.g = (ratio) * 0xff; 
//		f->p.img.color.rgba.b = (1-ratio) * 0xff; 

		if (ratio == 0)
		f->p.img.color.hex = 0xffffff;
	
		
		if (iter % 3 == 0)
			f->p.img.color.hex = (1-ratio) * 0x0000ff; 
			//f->p.img.color.rgba.b = (iter / f->max_iter) * 0xff; 
		if (iter % 3 == 1)
			f->p.img.color.hex = (1-ratio) * 0x00ff00; 
//			f->p.img.color.rgba.g = iter * 0xff / f->max_iter;
		if (iter % 3 == 2)
			f->p.img.color.hex = (1-ratio) * 0xff0000; 
//			f->p.img.color.rgba.r = iter * 0xff / f->max_iter;
	}
	if (iter == f->max_iter)
		f->p.img.color.hex = 0x000000;

}
