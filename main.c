/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:00:48 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/16 16:35:55 by fdelsing         ###   ########.fr       */
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
				"\n\t- ./fractol BurningShip\n\t- ./fractol Sierpinski");
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
			ft_strcmp(arg, "bla") != 0 &&
			ft_strcmp(arg, "Multibrot") != 0 )
		crash(1);
}

int		fract_name(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		return (0);
	if (ft_strcmp(name, "Julia") == 0)
		return (1);
	if (ft_strcmp(name, "BurningShip") == 0)
		return (2);
	if (ft_strcmp(name, "Sierpinski") == 0)
		return (3);
	if (ft_strcmp(name, "bla") == 0)
		return (4);
	if (ft_strcmp(name, "Multibrot") == 0)
		return (5);

	return (0);
}

void	init_context(t_context *f)
{
	f->palette = 0;
	f->d = 2;
	f->m_x = 93;
	f->m_y = 52;
	f->max_iter = 50;
	f->ratio = 2.1 / (WIN_Y / 2);
	f->zoom = 1;
}

int		main(int argc, char **argv)
{
	t_context	f;
	int			i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			check_arg(argv[i]);
			f.name = fract_name(argv[i]);
			ft_init_mlx(&f.p, argv[i]);
			init_context(&f);
			fractals(&f);
			i++;
		}
		hook(&f);
	}
	else
		crash(1);
	return (0);
}
