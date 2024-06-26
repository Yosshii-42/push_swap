/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:11:22 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/25 22:10:22 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_3(t_list **la)
{
	int	index0;
	int	index1;
	int	index2;

	index0 = (*la)->index;
	index1 = (*la)->next->index;
	index2 = (*la)->next->next->index;
	if (index0 < index2 && index2 < index1)
	{
		sa(la);
		ra(la);
	}
	else if (index1 < index0 && index0 < index2)
		sa(la);
	else if (index2 < index0 && index0 < index1)
		rra(la);
	else if (index2 < index1 && index1 < index0)
	{
		ra(la);
		sa(la);
	}
	else if (index1 < index2 && index2 < index0)
		ra(la);
}

void	operation_4(t_list **la, t_list **lb, int index)
{
	int		order;

	order = find_index(la, index, 4);
	if (order == 1)
		ra(la);
	else if (order == 2 || order == 3)
	{
		while (order < 4)
		{
			rra(la);
			order++;
		}
	}
	pb(la, lb);
	operation_3(la);
	pa(lb, la);
}

void	operation_5(t_list **la, t_list **lb)
{
	int	order;

	order = find_index(la, 0, 5);
	if (order == 1 || order == 2)
	{
		while (order > 0)
		{
			ra(la);
			order--;
		}
	}
	else if (order == 3 || order == 4)
	{
		while (order < 5)
		{
			rra(la);
			order++;
		}
	}
	pb(la, lb);
	operation_4(la, lb, 1);
	pa(lb, la);
}

void	operation_6_to_20(t_list **la, t_list **lb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*la)->index == i)
		{
			pb(la, lb);
			i++;
		}
		else
			ra(la);
	}
	while (i > 0)
	{
		pa(lb, la);
		i--;
	}
}

void	operation_x(t_list **la, t_list **lb, int size)
{
	int	i;
	int	n;

	operation_pb(la, lb, size);
	i = 0;
	while (i < size)
	{
		n = find_index(lb, size - 1 - i, size - i);
		if (n < (size - i) / 2)
			rotate_n(la, lb, n);
		else
			rev_rotate_n(la, lb, (size - i) - n);
		i++;
	}
}
