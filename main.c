/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:00:48 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/06 18:41:39 by fdelsing         ###   ########.fr       */
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
	if (i == 3)
		ft_putendl("You have succesfully exited the programm.");
	exit(0);
}

void	check_arg(char *arg)
{
	if (ft_strcmp(arg, "Mandelbrot") != 0 &&
			ft_strcmp(arg, "Julia") != 0)
		crash(1);
}

int		fract_name(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		return (0);
	if (ft_strcmp(name, "Julia") == 0)
		return (1);
	return (0);
}

void	init_context(t_context *f, char *name)
{
	f->max_iter = 60;
	f->ratio = 2.1 / (WIN_Y / 2);
	f->zoom = 1;
	f->name = fract_name(name);
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
			ft_init_mlx(&f.p, argv[i]);
			init_context(&f, argv[i]);
			if (f.name == 0)
				travel_map_mand(&f);
			i++;
		}
		mlx_hook(f.p.win, 4, 1 << 8, mousehook, &f);
		mlx_hook(f.p.win, 6, 0, mousepos, &f);
		mlx_hook(f.p.win, 2, 1 << 8, keyhook, &f);
		mlx_loop(f.p.mlx);
	}
	else
		crash(1);
	return (0);
}
