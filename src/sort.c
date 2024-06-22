#include "../push_swap.h"

void	sort_order(int size, t_list **la, t_list **lb)
{
	if (size == 2)
	{
		if ((*la)->index > (*la)->next->index)
			sa(la);
	}
	else if (size == 3)
		operation_3(la);
	else if (size == 4)
		operation_4(la, lb, 0);
	else if (size == 5)
		operation_5(la, lb);
	else
		operation_x(la, lb, size);
}

void	operation_3(t_list **la)
{
	int	index0;
	int	index1;
	int	index2;

	index0 = (*la)->index;
	index1 = (*la)->next->index;
	index2 = (*la)->next->next->index;
	if (index0 < index2 && index2 < index1)
	{
		sa(la);
		ra(la);
	}
	else if (index1 < index0 && index0 < index2)
		sa(la);
	else if (index2 < index0 && index0 < index1)
		rra(la);
	else if (index2 < index1 && index1 < index0)
	{
		ra(la);
		sa(la);
	}
	else if (index1 < index2 && index2 < index0)
		ra(la);
}

int	find_index(t_list **lst, int index, int size) //目的の index　の位置を確認する
{
	t_list	*ptr;
    int     order;

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

// int	find_next_order(t_list **lst, int index, int size) //目的の index の次の位置を確認する
// {
// 	t_list	*ptr;
// 	int		next_order;

// 	ptr = *lst;
// 	next_order = 0;
// 	while (next_order < size)
// 	{
// 		if (ptr->index < index)
// 			return (next_order);
// 		else
// 			ptr = ptr->next;
// 		next_order++;
// 	}
// 	return (-1);
// }

// void	push_2(t_list **la, t_list **lb)
// {
// 	pb(la, lb);
// 	pb(la, lb);
// 	if ((*lb)->index < (*lb)->next->index)
// 		ra(lb);
// }

void	rotate_n(t_list **la, t_list **lb, int n)
{
	while (n--)
		rb(lb);
	pa(lb, la);
}

void	rev_rotate_n(t_list **la, t_list **lb, int n)
{
	while (n--)
		rrb(lb);
	pa(lb, la);
}

void	operation_4(t_list **la, t_list **lb, int index)
{
	int		order;

	order = find_index(la, index, 4);
	if (order == 1)
		ra(la);
	else if (order == 2 || order == 3)
	{
		while (order < 4)
		{
			rra(la);
			order++;
		}
	}
	pb(la, lb);
	operation_3(la);
	pa(lb, la);
}

void	operation_5(t_list **la, t_list **lb)
{
	int	order;

	order = find_index(la, 0, 5);
	if (order == 1 || order == 2)
	{
		while (order > 0)
		{
			ra(la);
			order--;
		}
	}
	else if (order == 3 || order == 4)
	{
		while (order < 5)
		{
			rra(la);
			order++;
		}
	}
	pb(la, lb);
	operation_4(la, lb, 1);
	pa(lb, la);
}

void	operation_x(t_list **la, t_list **lb, int size)
{
	int	range;
	int	i;
	int	max;
	int	n;
	int	quater_range;

	range = size / 12;
	quater_range = range * 0.85;
	i = 0;
	max = INT_MIN;
	while (i < size)
	{
		if ((*la)->index < range)
		{
			pb(la, lb);
			if ((*lb)->index > max)
				max = (*lb)->index;
			if ((*lb)->index < max - quater_range)
				rb(lb);
			else if ((*lb)->index < (*lb)->next->index)
				sb(lb);
			range++;
			i++;
		}
		else
			ra(la);
	}
	i = 0;
	while (i < size)
	{
		n = find_index(lb, size - 1 - i, size - i);
		if (n <= (size - i) / 2)
			rotate_n(la, lb, n);
		else
			rev_rotate_n(la, lb, (size - i) - n);
		i++;
	}

}
