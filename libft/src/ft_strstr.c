/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:05:51 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/29 13:08:25 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;

	j = 0;
	while (haystack[j] == needle[j] && haystack[j])
		j++;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (haystack[j] == '\0')
		return (NULL);
	return (ft_strstr(haystack + 1, needle));
}
