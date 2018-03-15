/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_color.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:38:18 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/15 23:49:47 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef union	u_color
{
	unsigned int	hex;
	struct	s_rgba
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	}		rgba;
}				t_color;
