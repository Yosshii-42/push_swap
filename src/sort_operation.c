/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:28:15 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/30 13:28:16 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_operation(int size, t_list **la)
{
	t_list	*lb;

	lb = NULL;
	if (size == 2)
	{
		if ((*la)->index > (*la)->next->index)
			sa(la, MANDATORY);
	}
	else if (size == 3)
		operation_3(la);
	else if (size == 4)
		operation_4(la, &lb, 0);
	else if (size == 5)
		operation_5(la, &lb);
	else if (size > 5 && size < 20)
		operation_6_to_20(la, &lb, size);
	else
		operation_x(la, &lb, size);
}
