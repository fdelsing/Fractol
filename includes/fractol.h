/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:19:22 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/06 18:41:41 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <math.h>
# include <ft_init_mlx.h>

typedef	struct	s_context
{
	t_param	p;
	int		name;
	int		max_iter;
	double	ratio;
	double	zoom;
	int		m_x;
	int		m_y;
}				t_context;

void	crash(int i);
void	ft_put_pixel(int *data_img, int x, int y, t_param *p);
void	ft_init_mlx(t_param *p, char *win_name);
void	travel_map_mand(t_context *f);

int		mandelbrot(t_context *f, double c_r, double c_i);

int		keyhook(int keycode, t_context *f);
int		mousehook(int button, int x, int y, t_context *f);
int		translation(int keycode, t_context *f);
int		mousepos(int x, int y, t_context *f);

#endif
