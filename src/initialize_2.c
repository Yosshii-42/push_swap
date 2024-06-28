/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:56:08 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/28 19:04:38 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

void	ft_free(t_list **lst)
{
	if (*lst)
		list_clear(lst);
}

int	check_order(int size, t_list **la)
{
	t_list	*ptr;

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