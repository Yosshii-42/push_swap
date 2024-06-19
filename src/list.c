/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:03:18 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/16 20:03:32 by yotsurud         ###   ########.fr       */
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
	new->pre = NULL;
	new->next = NULL;
	return (new);
}

void	list_add(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
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
		(*lst)->pre = new;
		new->pre = last;
		new->next = (*lst);
		*lst = new;
	}
}

t_list	*list_last(t_list *lst)
{
	t_list	*first;

	if (!lst)
		return (NULL);
	first = lst;
	while (lst->next)
	{
		lst = lst->next;
		if (lst == first)
			break ;
	}
	return (lst);
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
		ptr = NULL;
		free(ptr);
		if (*lst == first)
			break ;
	}
	lst = NULL;
}
