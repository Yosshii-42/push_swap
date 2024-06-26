/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:55:41 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/26 18:55:42 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **la)
{
	func_s(la);
	write(1, "sa\n", 3);
}

void	sb(t_list **lb)
{
	func_s(lb);
	write(1, "sb\n", 3);
}

void	ss(t_list **la, t_list **lb)
{
	func_s(la);
	func_s(lb);
	write(1, "ss\n", 3);
}

void	pa(t_list **lst1, t_list **lst2)
{
	func_p(lst1, lst2);
	write(1, "pa\n", 3);
}

void	pb(t_list **lst1, t_list **lst2)
{
	func_p(lst1, lst2);
	write(1, "pb\n", 3);
}
