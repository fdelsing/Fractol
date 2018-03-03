/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:25:57 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/29 14:19:03 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fct(const char *haystack, const char *needle,
		size_t len, size_t i)
{
	int	occurence;
	int	j;
	int dif;

	j = 0;
	dif = 0;
	if (haystack[0] != 0)
	{
		while (haystack[i] && haystack[i] != needle[j] && (i < len))
			i++;
		occurence = i;
		while (haystack[i] && haystack[i++] == needle[j++] && (i <= len))
		{
			if (needle[j] == '\0')
				return ((char*)haystack + occurence + dif);
			while ((haystack[i] && haystack[i] != needle[j])
					&& haystack[i] && (i < len))
			{
				dif++;
				i = (occurence + dif);
				j = 0;
			}
		}
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == 0)
		return ((char*)haystack);
	return (ft_fct(haystack, needle, len, i));
}
