/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_p_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:14:18 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/16 20:15:16 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **la)
{
	list_swap(la);
	write(1, "sa\n", 3);
}

void	sb(t_list **lb)
{
	list_swap(lb);
	write(1, "sb\n", 3);
}

void	ss(t_list **la, t_list **lb)
{
	list_swap(la);
	list_swap(lb);
	write(1, "ss\n", 3);
}

void	pa(t_list **lst1, t_list **lst2)
{
	list_push(lst1, lst2);
	write(1, "pa\n", 3);
}

void	pb(t_list **lst1, t_list **lst2)
{
	list_push(lst1, lst2);
	write(1, "pb\n", 3);
}
