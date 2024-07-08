/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:24:00 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/04 14:33:04 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bonus_sort_operation(t_list **la, t_list **lb, char *str)
{
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		if (*str == 's')
			bonus_operation_s(la, lb, str);
		else if (*str == 'p')
			bonus_operation_p(la, lb, str);
		else if (*str == 'r')
			bonus_operation_r(la, lb, str);
		else
		{
			put_error();
			exit(1);
		}
		free(str);
		str = NULL;
	}
}

void	bonus_operation_s(t_list **la, t_list **lb, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(la, BONUS);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(lb, BONUS);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(la, lb, BONUS);
	else
	{
		put_error();
		exit(1);
	}
}

void	bonus_operation_p(t_list **la, t_list **lb, char *str)
{
	if (!ft_strncmp(str, "pa\n", 3))
		pa(lb, la, BONUS);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(la, lb, BONUS);
	else
	{
		put_error();
		exit(1);
	}
}

void	bonus_operation_r(t_list **la, t_list **lb, char *str)
{
	if (!ft_strncmp(str, "ra\n", 3))
		ra(la, BONUS);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(lb, BONUS);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(la, lb, BONUS);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(la, BONUS);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(lb, BONUS);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(la, lb, BONUS);
	else
	{
		put_error();
		exit(1);
	}
}
