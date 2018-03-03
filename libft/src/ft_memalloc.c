/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:56:54 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/13 18:11:50 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (void*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void*)mem);
}
