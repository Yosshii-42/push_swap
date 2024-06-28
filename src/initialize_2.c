/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:56:08 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/28 15:23:00 by yotsurud         ###   ########.fr       */
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

void	ft_error(t_list **lst)
{
	if (*lst)
		list_clear(lst);
	ft_putstr_fd("Error\n", 2);
}
