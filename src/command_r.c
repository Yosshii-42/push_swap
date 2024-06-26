/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:16:24 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/26 15:46:27 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **la)
{
	func_r(la);
	write(1, "ra\n", 3);
}

void	rb(t_list **lb)
{
	func_r(lb);
	write(1, "rb\n", 3);
}

void	rr(t_list **la, t_list **lb)
{
	func_r(la);
	func_r(lb);
	write(1, "rr\n", 3);
}
