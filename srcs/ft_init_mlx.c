/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:46:37 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/21 12:27:00 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_init_mlx.h>
#include <mlx.h>

void	ft_init_mlx(t_param *p, char *win_name)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, win_name);
	p->c_x = WIN_X / 2;
	p->c_y = WIN_Y / 2;
	p->img.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->img.data_img = (int*)mlx_get_data_addr(p->img.img,
			&p->img.bpp, &p->img.s_l, &p->img.endian);
	p->img.color.hex = 0x0000FF;
}