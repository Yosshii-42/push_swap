/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_6_to_20.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:26:51 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/30 13:26:52 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_6_to_20(t_list **la, t_list **lb, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*la)->index == i)
		{
			pb(la, lb, MANDATORY);
			i++;
		}
		else
			ra(la, MANDATORY);
	}
	while (i > 0)
	{
		pa(lb, la, MANDATORY);
		i--;
	}
}
