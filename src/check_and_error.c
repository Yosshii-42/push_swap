/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:04:08 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/22 16:04:12 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_number(long nbr)
{
	return (nbr >= INT_MIN && nbr <= INT_MAX);
}

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	check_double(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (tab[j] == tab[j - 1])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
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
