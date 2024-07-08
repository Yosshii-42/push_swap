/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:01:21 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/03 20:45:00 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	put_bonus_result(t_list **la, t_list **lb, int size)
{
	if (check_order(size, la) && !list_size(lb))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
