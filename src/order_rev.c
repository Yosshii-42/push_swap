/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_rev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:15:30 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/16 20:16:15 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **la)
{
	rev_rotate(la);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lb)
{
	rev_rotate(lb);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **la, t_list **lb)
{
	rev_rotate(la);
	rev_rotate(lb);
	write(1, "rrr\n", 4);
}
