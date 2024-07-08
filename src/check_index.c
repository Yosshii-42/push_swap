/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:29:48 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/04 14:46:33 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_index(t_list **lst, int index, int size)
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
