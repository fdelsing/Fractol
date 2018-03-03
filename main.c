/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:00:48 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/04 00:25:49 by fdelsing         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_param	p;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			check_arg(argv[i]);
			ft_init_mlx(&p, argv[i]);
			fractol(&p);
			i++;
		}
		mlx_loop(p.mlx);
	}
	else
		crash(1);
	return (0);
}
