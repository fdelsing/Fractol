/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:53:16 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/15 21:44:35 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_MLX_H
# define FT_INIT_MLX_H

#include <mlx.h>
#include <s_color.h>

# define WIN_X 1200
# define WIN_Y 600

typedef	struct	s_img
{
	int		bpp;
	int		s_l;
	int		endian;
	void	*img;
	int		*data_img;
	t_color	color;
}				t_img;

typedef	struct	s_param
{
	void	*mlx;
	void	*win;
	int		c_x;
	int		c_y;
	t_img	img;
}				t_param;
#endif
