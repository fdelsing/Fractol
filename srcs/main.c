/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:00:48 by fdelsing          #+#    #+#             */
/*   Updated: 2018/04/12 16:12:29 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	crash(int i)
{
	if (i == 0)
		perror("ERROR");
	if (i == 1)
		ft_putendl("ERROR: Missing or invalid fractal name."
				"USAGE:\n\t- ./fractol Mandelbrot\n\t- ./fractol Julia"
				"\n\t- ./fractol Burningship\n\t- ./fractol Sierpinski\n\t"
				"- ./fractol Multibrot\n\t- ./fractol Bacteria\n\t"
				"- ./fractol Tricorn");
	if (i == 3)
		ft_putendl("You have succesfully exited the programm.");
	exit(0);
}

void	check_arg(char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") != 0 &&
			ft_strcmp(arg, "Julia") != 0 &&
			ft_strcmp(arg, "Burningship") != 0 &&
			ft_strcmp(arg, "Sierpinski") != 0 &&
			ft_strcmp(arg, "Multibrot") != 0 &&
			ft_strcmp(arg, "Bacteria") != 0 &&
			ft_strcmp(arg, "Tricorn") != 0)
		crash(1);
}

int		fract_name(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		return (0);
	if (ft_strcmp(name, "Julia") == 0)
		return (1);
	if (ft_strcmp(name, "Burningship") == 0)
		return (2);
	if (ft_strcmp(name, "Sierpinski") == 0)
		return (3);
	if (ft_strcmp(name, "Multibrot") == 0)
		return (4);
	if (ft_strcmp(name, "Bacteria") == 0)
		return (5);
	if (ft_strcmp(name, "Tricorn") == 0)
		return (6);
	return (0);
}

void	init_context(t_context *f)
{
	f->palette = 0;
	f->d = 2;
	f->max_iter = 52;
	f->ratio = 2.1 / (WIN_Y / 2);
	f->zoom = 1;
	f->zoomx = 0;
	f->zoomy = 0;
}

int		main(int argc, char **argv)
{
	t_context	f;

	if (argc > 1)
	{
		check_arg(argv[1]);
		f.name = fract_name(argv[1]);
		ft_init_mlx(&f.p, argv[1]);
		init_context(&f);
		travel_map(&f);
		hook(&f);
	}
	else
		crash(1);
	return (0);
}
