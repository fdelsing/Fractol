/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:00:18 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/05 22:00:36 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <ft_init_mlx.h>

void	ft_put_pixel(int *data_img, int x, int y, t_param *p)
{
	if (y >= 0 && y < WIN_Y && x >= 0 && x < WIN_X)
		data_img[(y * WIN_X) + x] = p->img.color;
}
