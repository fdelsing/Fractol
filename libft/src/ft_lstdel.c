/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:02:38 by fdelsing          #+#    #+#             */
/*   Updated: 2017/11/22 14:02:32 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (!alst)
		return ;
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		tmp->content = NULL;
		tmp->content_size = 0;
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
}
