/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:55:59 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/26 18:56:00 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **la)
{
	func_rr(la);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lb)
{
	func_rr(lb);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **la, t_list **lb)
{
	func_rr(la);
	func_rr(lb);
	write(1, "rrr\n", 4);
}
