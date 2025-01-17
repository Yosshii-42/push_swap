/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:03:18 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/02 19:10:59 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*list_new(int number)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = number;
	new->index = 0;
	new->pre = new;
	new->next = new;
	return (new);
}

void	list_add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	list_add_last(lst, new);
	*lst = (*lst)->pre;
}

void	list_add_last(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->pre = new;
	}
	else
	{
		last = (*lst)->pre;
		last->next = new;
		new->pre = last;
		new->next = *lst;
		(*lst)->pre = new;
	}
}

int	list_size(t_list **lst)
{
	t_list	*ptr;
	int		i;

	if (!lst || !(*lst))
		return (0);
	ptr = *lst;
	i = 0;
	while (*lst)
	{
		i++;
		*lst = (*lst)->next;
		if (*lst == ptr)
			break ;
	}
	return (i);
}

void	list_clear(t_list **lst)
{
	t_list	*first;
	t_list	*ptr;

	if (!lst || !(*lst))
		return ;
	first = *lst;
	while (*lst)
	{
		ptr = *lst;
		(*lst)->num = 0;
		(*lst)->index = 0;
		*lst = (*lst)->next;
		free(ptr);
		ptr = NULL;
		if (*lst == first)
			break ;
	}
	lst = NULL;
}
