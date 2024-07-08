/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:27:19 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/04 14:44:25 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_5(t_list **la, t_list **lb)
{
	int	order;

	order = check_index(la, 0, 5);
	if (order == 1 || order == 2)
	{
		while (order > 0)
		{
			ra(la, MANDATORY);
			order--;
		}
	}
	else if (order == 3 || order == 4)
	{
		while (order < 5)
		{
			rra(la, MANDATORY);
			order++;
		}
	}
	pb(la, lb, MANDATORY);
	operation_4(la, lb, 1);
	pa(lb, la, MANDATORY);
}
