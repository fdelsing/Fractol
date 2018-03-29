/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:19:22 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/29 17:44:39 by fdelsing         ###   ########.fr       */
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
	int		m_x;
	int		m_y;
	int		palette;
	double	ratio;
	double	zoom;
	double	zoomx;
	double	zoomy;
	double	d;
}				t_context;

void			fractals(t_context *f);
void			init_context(t_context *f);
void			crash(int i);
void			hook(t_context *f);
void			ft_put_pixel(int *data_img, int x, int y, t_param *p);
void			ft_init_mlx(t_param *p, char *win_name);
void			color(int iter, t_context *f);

void			mandelbrot(t_context *f);
void			multibrot(t_context *f);
void			julia(t_context *f);
void			burning_ship(t_context *f);
void			sierpinski(t_context *f);
void			bla(t_context *f);

int				keyhook(int keycode, t_context *f);
int				mousehook(int button, int x, int y, t_context *f);
int				mousepos(int x, int y, t_context *f);
int				zoom(int keycode, t_context *f);

#endif
