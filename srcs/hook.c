/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:59:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/29 17:27:34 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		translation(int keycode, t_context *f)
{
	if (keycode == 123)
		f->p.c_x += 5;
	if (keycode == 124)
		f->p.c_x -= 5;
	if (keycode == 125)
		f->p.c_y -= 5;
	if (keycode == 126)
		f->p.c_y += 5;
	return (0);
}

int				keyhook(int keycode, t_context *f)
{
	if (keycode == 53)
		crash(3);
	if (keycode >= 123 && keycode <= 126)
		translation(keycode, f);
	if (keycode == 49)
	{
		f->palette++;
		if (f->palette == 3)
			f->palette = 0;
	}
	if (keycode == 256)
	{
		init_context(f);
		f->p.c_x = WIN_X / 2;
		f->p.c_y = WIN_Y / 2;
	}
	if (keycode == 47)
		f->d += 0.2;
	if (keycode == 43 && f->d >= 0)
		f->d -= 0.1;
	if (keycode == 27 || keycode == 24)
		zoom(keycode, f);
	fractals(f);
	return (0);
}

int				mousehook(int button, int x, int y, t_context *f)
{
	double	zm_sp;

	zm_sp = 1.2;
	ft_bzero((char*)f->p.img.data_img, (WIN_X * WIN_Y) * 4);
	if (button == 5)
	{
		f->zoom *= zm_sp;
		f->zoomx += (double)(x - f->p.c_x) * f->ratio *
			(f->zoom * (1 / zm_sp - 1));
		f->zoomy += (double)(y - f->p.c_y) * f->ratio *
			(f->zoom * (1 / zm_sp - 1));
	}
	if (button == 4)
	{
		f->zoom /= zm_sp;
		f->zoomx += (double)(x - f->p.c_x) * f->ratio * (f->zoom * (zm_sp - 1));
		f->zoomy += (double)(y - f->p.c_y) * f->ratio * (f->zoom * (zm_sp - 1));
	}
	fractals(f);
	return (0);
}

int				mousepos(int x, int y, t_context *f)
{
	f->m_x = x;
	f->m_y = y;
	if (f->name == 1)
	{
		ft_bzero((char*)f->p.img.data_img, (WIN_X * WIN_Y) * 4);
		fractals(f);
	}
	return (0);
}

void			hook(t_context *f)
{
	mlx_hook(f->p.win, 6, 0, mousepos, f);
	mlx_hook(f->p.win, 4, 1 << 8, mousehook, f);
	mlx_hook(f->p.win, 2, 1 << 8, keyhook, f);
	mlx_loop(f->p.mlx);
}
