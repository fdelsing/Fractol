/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:00:47 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/31 16:12:50 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_fct(t_list *tmp, t_list *lst, t_list *(*f) (t_list *elem))
{
	if (!(tmp->next = (t_list*)malloc(sizeof(t_list) * 1)))
	{
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
		return (NULL);
	}
	if (!((tmp->next)->content = (void*)malloc(sizeof(f(lst)->content) *
					(f(lst)->content_size))))
	{
		while (tmp)
		{
			free(tmp->content);
			free(tmp);
			tmp = tmp->next;
		}
		return (NULL);
	}
	return (tmp);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	tmp = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp = ft_fct(tmp, lst, f);
		ft_memcpy((tmp->next)->content,
				(void*)(f(lst)->content), f(lst)->content_size);
		(tmp->next)->content_size = f(lst)->content_size;
		(tmp->next)->next = (NULL);
		tmp = tmp->next;
	}
	return (new);
}
