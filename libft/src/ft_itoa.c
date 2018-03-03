/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:05:52 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/20 14:10:42 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void		ft_fill(char *str, int n, int neg)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		i++;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (neg == 2)
	{
		str[i] = '2';
		i++;
	}
	if (neg == 1 || neg == 2)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

static void		ft_swap(char *str, int len)
{
	char	bfr;
	int		i;

	i = 0;
	while (i < len)
	{
		bfr = str[i];
		str[i] = str[len];
		str[len] = bfr;
		i++;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		neg;

	neg = 0;
	if (!(str = (char *)malloc(sizeof(char) * ((ft_len(n) + 1)))))
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -147483648;
			neg++;
		}
		n = -n;
		neg++;
	}
	ft_fill(str, n, neg);
	ft_swap(str, (ft_strlen(str) - 1));
	return (str);
}
