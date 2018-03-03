/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:07:56 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/31 16:12:34 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	if (!alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	(*alst)->content = NULL;
	(*alst)->content_size = 0;
	free(*alst);
	*alst = NULL;
}
