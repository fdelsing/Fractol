/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:59:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/05 23:02:15 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		translation(int keycode, t_context *f)
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

int		keyhook(int keycode, t_context *f)
{
	ft_bzero((char*)f->p.img.data_img, (WIN_X * WIN_Y) * 4);
	if (keycode == 53)
		crash(3);
	if (keycode >= 123 && keycode <= 126)
		translation(keycode, f);
	travel_map(f);
	return (0);
}

int		mousehook(int button, int x, int y, t_context *f)
{
//	printf("button = %d\n", button);
//	printf("x = %d\n", x);
//	printf("y = %d\n", y);
	ft_bzero((char*)f->p.img.data_img, (WIN_X * WIN_Y) * 4);
	if (button == 5) //  zoom out
//	{
		f->zoom *= 1 / 0.8;
//		f->p.c_x =  WIN_X - x ;
//		f->p.c_y =  WIN_Y + y ;
//	}
	if (button == 4) // zoom in
//	{
		f->zoom *= 0.8;
//		f->p.c_x += (WIN_X / 2) - x;
//		f->p.c_y += (WIN_Y / 2) - y;
//	}
	x = 0;
	y = 0;
	travel_map(f);
	return (0);
}
