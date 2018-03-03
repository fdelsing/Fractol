/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:40:24 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/24 11:43:33 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbw(char const *s, char c)
{
	int	w;
	int i;

	w = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		if (s[i] == c || s[i] == '\0')
		{
			w++;
			while (s[i] == c)
				i++;
		}
	}
	return (w);
}

static char	**ft_malloclet2(char **str, int j, int let)
{
	if (!(str[j] = (char*)malloc(sizeof(char) * (let + 1))))
	{
		while (j - 1 >= 0)
		{
			j--;
			free(str[j]);
		}
		free(str);
		return (NULL);
	}
	return (str);
}

static char	**ft_malloclet(char const *s, char c, char **str)
{
	int let;
	int i;
	int j;

	let = 0;
	i = 0;
	j = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		let++;
		if (s[i] == c || s[i] == '\0')
		{
			str = ft_malloclet2(str, j, let);
			j++;
			let = 0;
			while (s[i] == c)
				i++;
		}
	}
	return (str);
}

static void	ft_fillstr(char const *s, char c, char **str, int w)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k] == c && s[k] != '\0')
		k++;
	while (s[k] != c && s[k] != '\0')
	{
		str[i][j] = s[k];
		k++;
		j++;
		if (s[k] == c && s[k] != '\0' && i <= w)
		{
			str[i][j] = '\0';
			i++;
			j = 0;
			while (s[k] == c && s[k] != '\0')
				k++;
		}
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		w;

	if (!s)
		return (NULL);
	w = ft_nbw(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (w + 1))))
		return (NULL);
	str[w] = 0;
	ft_malloclet(s, c, str);
	ft_fillstr(s, c, str, w);
	return (str);
}
