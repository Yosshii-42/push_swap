/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:45:31 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/02 14:45:32 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_double(t_list **la)
{
	t_list	*i;
	t_list	*j;
	int		count;

	i = *la;
	while (1)
	{
		count = 0;
		j = *la;
		while (1)
		{
			if (i->num == j->num)
				count++;
			j = j->next;
			if (j == *la)
				break ;
		}
		if (count > 1)
			return (FALSE);
		i = i->next;
		if (i == *la)
			break ;
	}
	return (TRUE);
}
