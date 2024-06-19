/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:11:18 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/16 20:14:09 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	list_swap(t_list **lst)
{
	t_list	*last;
	t_list	*second;
	t_list	*third;
	int		len;

	len = list_size(lst);
	if (len <= 1)
		return ;
	if (len == 2)
		*lst = (*lst)->next;
	else
	{
		last = (*lst)->pre;
		second = (*lst)->next;
		third = (*lst)->next->next;
		last->next = (*lst)->next;
		third->pre = (*lst);
		(*lst)->next = third;
		(*lst)->pre = second;
		second->next = *lst;
		second->pre = last;
		*lst = second;
	}
}

void	list_push(t_list **lst1, t_list **lst2)
{
	t_list	*last;

	if (!(*lst1))
		return ;
	last = (*lst1)->pre;
	if ((*lst1)->next == *lst1)
	{
		list_add(lst2, *lst1);
		*lst1 = NULL;
	}
	else
	{
		last->next = (*lst1)->next;
		((*lst1)->next)->pre = last;
		list_add(lst2, *lst1);
		*lst1 = last->next;
	}
}

void	rotate(t_list **lst)
{
	*lst = (*lst)->next;
}

void	rev_rotate(t_list **lst)
{
	*lst = (*lst)->pre;
}
