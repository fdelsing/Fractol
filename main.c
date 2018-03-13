/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:00:48 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/13 23:09:12 by fdelsing         ###   ########.fr       */
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
			ft_strcmp(arg, "BurningShip") != 0 &&
			ft_strcmp(arg, "Sierpinski") != 0 )
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
	return (0);
}

void	init_context(t_context *f)
{
	f->m_x = 93;
	f->m_y = 52;
	f->max_iter = 3;
	f->ratio = 2.1 / (WIN_Y / 2);
	printf("ratio = %f\n", f->ratio);
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
			if (f.name == 0)
				mandelbrot(&f);
			if (f.name == 1)
				julia(&f);
			if (f.name == 2)
				burning_ship(&f);
			if (f.name == 3)
				sierpinski(&f);
			i++;
		}
		printf("mx = %f my = %f\n", f.m_x * f.ratio, f.m_y * f.ratio);
		mlx_hook(f.p.win, 6, 0, mousepos, &f);
		mlx_hook(f.p.win, 4, 1 << 8, mousehook, &f);
	//	mlx_hook(f.p.win, 6, 0, mousepos, &f);
		mlx_hook(f.p.win, 2, 1 << 8, keyhook, &f);
		mlx_loop(f.p.mlx);
	}
	else
		crash(1);
	return (0);
}
