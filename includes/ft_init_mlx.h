/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:53:16 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/03 23:19:39 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_MLX_H
# define FT_INIT_MLX_H

#include <mlx.h>

# define WIN_X 2500
# define WIN_Y 1200

typedef	struct	s_img
{
	int		bpp;
	int		s_l;
	int		endian;
	void	*img;
	int		*data_img;
	int		color;
}				t_img;

typedef	struct	s_param
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_param;
#endif
