/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:07:32 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/27 16:44:49 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index(t_list **lst, int index, int size)
{
	t_list	*ptr;
	int		order;

	ptr = *lst;
	order = 0;
	while (order < size)
	{
		if (ptr->index == index)
			return (order);
		else
			ptr = ptr->next;
		order++;
	}
	return (-1);
}

void	marge_or_not(t_list **la, t_list **lb, int range)
{
	if (*la && (*la)->index && !((*la)->index < range))
		rr(la, lb);
	else
		rb(lb);
}

void	operation_pb(t_list **la, t_list **lb, int size, int range)
{
	int	max;
	int	quater_range;

	quater_range = range * 0.8;
	max = INT_MIN;
	while (size)
	{
		if ((*la)->index < range)
		{
			pb(la, lb);
			if ((*lb)->index > max)
				max = (*lb)->index;
			if ((*lb)->index < max - quater_range)
				marge_or_not(la, lb, range);
			else if ((*lb)->index < (*lb)->next->index)
				sb(lb);
			range++;
			size--;
		}
		else
			ra(la);
	}
}

void	rotate_n(t_list **la, t_list **lb, int n)
{
	while (n--)
		rb(lb);
	pa(lb, la);
}

void	rev_rotate_n(t_list **la, t_list **lb, int n)
{
	while (n--)
		rrb(lb);
	pa(lb, la);
}
