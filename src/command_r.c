/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:55:51 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/26 18:55:52 by yotsurud         ###   ########.fr       */
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
