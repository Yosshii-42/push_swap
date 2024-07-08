/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:27:43 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/06 14:57:25 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_x(t_list **la, t_list **lb, int size)
{
	int	i;
	int	n;
	int	range;

	if (size <= 200)
		range = size / 10;
	else
		range = size / 12;
	operation_pb(la, lb, size, range);
	i = 0;
	while (i < size)
	{
		n = check_index(lb, size - 1 - i, size - i);
		if (n <= (size - i) / 2)
			rotate_n(la, lb, n);
		else
			rev_rotate_n(la, lb, (size - i) - n);
		i++;
	}
}

void	operation_pb(t_list **la, t_list **lb, int size, int range)
{
	int	max;
	int	sub_range;

	if (!(*la))
		return ;
	sub_range = range * 0.8;
	max = INT_MIN;
	while (size)
	{
		if ((*la)->index < range)
		{
			pb(la, lb, MANDATORY);
			if ((*lb)->index > max)
				max = (*lb)->index;
			if ((*lb)->index < max - sub_range)
				marge_or_not(la, lb, range);
			else if ((*lb)->index < (*lb)->next->index)
				sb(lb, MANDATORY);
			range++;
			size--;
		}
		else
			ra(la, MANDATORY);
	}
}

void	marge_or_not(t_list **la, t_list **lb, int range)
{
	if (*la && (*la)->index && !((*la)->index < range))
		rr(la, lb, MANDATORY);
	else
		rb(lb, MANDATORY);
}

void	rotate_n(t_list **la, t_list **lb, int n)
{
	while (n--)
		rb(lb, MANDATORY);
	pa(lb, la, MANDATORY);
}

void	rev_rotate_n(t_list **la, t_list **lb, int n)
{
	while (n--)
		rrb(lb, MANDATORY);
	pa(lb, la, MANDATORY);
}
