/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:51:25 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/16 18:31:03 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		etrim;
	int		i;

	etrim = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	etrim = ft_strlen(s) - 1;
	if (*s == '\0')
		etrim = 0;
	while (s[etrim] == ' ' || s[etrim] == '\n' || s[etrim] == '\t')
		etrim--;
	if (!(str = (char*)malloc(sizeof(char) * etrim + 1)))
		return (NULL);
	i = 0;
	while (i <= etrim)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
