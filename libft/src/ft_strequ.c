/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:15:11 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/15 17:22:12 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != 0 && s2 != 0)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	}
	return (0);
}
