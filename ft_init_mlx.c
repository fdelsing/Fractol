/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:46:37 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/04 19:46:34 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_init_mlx.h>
#include <mlx.h>

void	ft_init_mlx(t_param *p, char *win_name)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, win_name);
	p->img.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->img.data_img = (int*)mlx_get_data_addr(p->img.img,
			&p->img.bpp, &p->img.s_l, &p->img.endian);
	p->img.color = 0x0000FF;
}
