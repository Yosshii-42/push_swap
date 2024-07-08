/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:25:35 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/04 14:43:45 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_4(t_list **la, t_list **lb, int index)
{
	int		order;

	order = check_index(la, index, 4);
	if (order == 1)
		ra(la, MANDATORY);
	else if (order == 2 || order == 3)
	{
		while (order < 4)
		{
			rra(la, MANDATORY);
			order++;
		}
	}
	pb(la, lb, MANDATORY);
	operation_3(la);
	pa(lb, la, MANDATORY);
}
