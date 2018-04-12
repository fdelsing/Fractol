/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:59:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 17:52:06 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		trans_pal_iter(int keycode, t_context *f)
{
	if (keycode == 123)
		f->p.c_x += 5;
	if (keycode == 124)
		f->p.c_x -= 5;
	if (keycode == 125)
		f->p.c_y -= 5;
	if (keycode == 126)
		f->p.c_y += 5;
	if (keycode == 49)
	{
		f->palette++;
		if (f->palette == 3)
			f->palette = 0;
	}
	if (keycode == 34)
		f->max_iter++;
	if (keycode == 32)
	{
		if (f->max_iter > 1)
			f->max_iter--;
	}
	return (0);
}

int				keyhook(int keycode, t_context *f)
{
	if (keycode == 53)
		crash(3);
	if ((keycode >= 123 && keycode <= 126) || keycode == 49 ||
			keycode == 32 || keycode == 34)
		trans_pal_iter(keycode, f);
	if (keycode == 71)
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
	travel_map(f);
	return (0);
}

int				mousehook(int button, int x, int y, t_context *f)
{
	double	zm_sp;

	zm_sp = 1.2;
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
	travel_map(f);
	return (0);
}

int				mousepos(int x, int y, t_context *f)
{
	f->m_x = x;
	f->m_y = y;
	if (f->name == 1 || f->name == 5)
		travel_map(f);
	return (0);
}

void			hook(t_context *f)
{
	mlx_hook(f->p.win, 6, 0, mousepos, f);
	mlx_hook(f->p.win, 4, 1 << 8, mousehook, f);
	mlx_hook(f->p.win, 2, 1 << 8, keyhook, f);
	mlx_loop(f->p.mlx);
}
