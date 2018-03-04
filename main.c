/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:00:48 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/04 21:21:03 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	crash(int i)
{
	if (i == 0)
		perror("ERROR");
	if (i == 1)
		ft_putendl("ERROR: Missing or invalid fractal name."
			"USAGE:\n\t- ./fractol Mandelbrot\n\t- ./fractol Julia");
	exit(0);
}

void	check_arg(char *arg)
{
	if (ft_strcmp(arg,"Mandelbrot") != 0 &&
			ft_strcmp(arg, "Julia") != 0)
		crash(1);
}

void	init_context(t_context *f)
{
	f->max_iter = 60;
	f->ratio = 2.1 / (WIN_Y / 2);
}

void	travel_map(t_param *p, t_context *f, int fractal)
{
	int x;
	int y;
	double c_r;
	double c_i;

	x = 0;
	while (x <= WIN_X)
	{
		y = 0;
		while (y <= WIN_Y)
		{
			if (fractal == 0)
			{
				c_r = (x - (WIN_X / 2)) * f->ratio;
				c_i = (y - (WIN_Y / 2)) * f->ratio;
				if (mandelbrot(f, c_r, c_i) == f->max_iter + 1)
					ft_put_pixel(p->img.data_img, x, y, p);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}

void	fractal(t_param *p, t_context *f, char *s)
{
	int			fractal;

	fractal = 0;
	s = NULL;
	//if (ft_strcmp(s, "Mandelbrot") == 0)
	//	if (ft_strcmp(s, Julia) == 0)
	//		julia(p);
	travel_map(p, f, fractal);	
}

int		main(int argc, char **argv)
{
	t_param	p;
	t_context f;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			check_arg(argv[i]);
			ft_init_mlx(&p, argv[i]);
			init_context(&f);
			fractal(&p, &f, argv[i]);
			i++;
		}

		mlx_loop(p.mlx);
	}
	else
		crash(1);
	return (0);
}
