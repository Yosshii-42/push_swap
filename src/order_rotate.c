/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:16:24 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/16 20:16:50 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **la)
{
	rotate(la);
	write(1, "ra\n", 3);
}

void	rb(t_list **lb)
{
	rotate(lb);
	write(1, "rb\n", 3);
}

void	rr(t_list **la, t_list **lb)
{
	rotate(la);
	rotate(lb);
	write(1, "rr\n", 3);
}
