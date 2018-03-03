/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:30:06 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/15 17:52:49 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int i;

	i = 0;
	while (s1 != NULL && s2 != NULL)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
		{
			i++;
			if (s1[i] == '\0' && s2[i] == '\0')
				return (0);
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
