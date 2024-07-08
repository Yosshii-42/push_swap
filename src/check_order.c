/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:19:02 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/02 15:19:03 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_order(int size, t_list **la)
{
	t_list	*ptr;

	if (!(*la))
		return (0);
	if (size == 1)
		return (1);
	ptr = *la;
	while (size > 1)
	{
		if (ptr->index + 1 == ptr->next->index)
			ptr = ptr->next;
		else
			return (0);
		size--;
	}
	if (size > 1)
		return (0);
	return (1);
}
