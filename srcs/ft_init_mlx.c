/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:53:34 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 17:54:52 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_init_mlx.h>
#include <mlx.h>

void	ft_init_mlx(t_param *p, char *win_name)
{
	p->mlx = mlx_init();
	if (!p->mlx)
		exit(0);
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, win_name);
	if (!p->win)
		exit(0);
	p->c_x = WIN_X / 2;
	p->c_y = WIN_Y / 2;
	p->img.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	if (!p->img.img)
		exit(0);
	p->img.data_img = (int*)mlx_get_data_addr(p->img.img,
			&p->img.bpp, &p->img.s_l, &p->img.endian);
	if (!p->img.data_img)
		exit(0);
	p->img.color.hex = 0x0000FF;
}
