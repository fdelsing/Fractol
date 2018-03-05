/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:19:22 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/05 23:02:18 by fdelsing         ###   ########.fr       */
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
	int		m_x;
	int		m_y;
	int		name;
	int		max_iter;
	int		hz;
	int		vt;
	double	ratio;
	double	zoom;
}				t_context;

void	crash(int i);
void	ft_put_pixel(int *data_img, int x, int y, t_param *p);
void	ft_init_mlx(t_param *p, char *win_name);
void	travel_map(t_context *f);

int		mandelbrot(t_context *f, double c_r, double c_i);

int		keyhook(int keycode, t_context *f);
int		mousehook(int button, int x, int y, t_context *f);
int		translation(int keycode, t_context *f);

#endif
