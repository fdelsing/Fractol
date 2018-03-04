/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:19:22 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/04 21:17:11 by fdelsing         ###   ########.fr       */
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
	int		max_iter;
	double	ratio;
}				t_context;

void	ft_put_pixel(int *data_img, int x, int y, t_param *p);
void	ft_init_mlx(t_param *p, char *win_name);
int		mandelbrot(t_context *f, double c_r, double c_i);

double	adapt_x(double x);
double	adapt_y(double y);



void	adapt(double *c_r, double *c_i);
#endif
