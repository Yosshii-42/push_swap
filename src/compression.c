/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:46:31 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/02 14:46:32 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	compression(t_list **la, int size)
{
	t_list	*i;
	t_list	*j;
	int		size_i;
	int		size_j;

	i = *la;
	size_i = 0;
	while (size_i < size)
	{
		j = (*la)->pre;
		size_j = 0;
		while (size_j < size)
		{
			if (i->num > j->num)
				(i->index)++;
			j = j->next;
			size_j++;
		}
		i = i->next;
		size_i++;
	}
}
