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
		operation_4(la, lb, size);
	// else
	// 	operation_5(la, lb, size);
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

// int	find_min(t_list **lst)
// {
// 	int		min;
// 	t_list	*ptr;
// 	t_list	*last;

// 	min = INT_MAX;
// 	ptr = *lst;
// 	last = *lst;
// 	while (ptr)
// 	{
// 		if (ptr->num < min)
// 			min = ptr->num;
// 		ptr = ptr->next;
// 		if (ptr == last)
// 			break ;
// 	}
// 	return (min);
// }

int	find_order(t_list **lst, int index, int size)
{
	t_list	*ptr;
    int     order;

	ptr = *lst;
    order = 0;
	while (order < size)
	{
		if (ptr->index == index)
			break ;
		else
			ptr = ptr->next;
		order++;
	}
	return (order);
}

void	operation_4(t_list **la, t_list **lb, int size)
{
	int	order;

	order = find_order(la, 0, size);
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
	pa(la, lb);
}

// void	operation_5(t_list **la, t_list **lb, int size)
// {
// 	int	size_a;
// 	int	size_b;

// 	size_a = size;
// 	sibe_b = size - sizea;
// 	while (size_a > 3)
// 	{
// 		pb(la, lb);
// 		pb(la, lb);
// 		size_a -= 2;
// 		while (size_a > 3)
// 		{

// 		}
// 	}
// }
