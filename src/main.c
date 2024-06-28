/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:28 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/28 19:01:47 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_operation(int size, t_list **la)
{
	t_list	*lb;

	lb = NULL;
	if (size == 2)
	{
		if ((*la)->index > (*la)->next->index)
			sa(la);
	}
	else if (size == 3)
		operation_3(la);
	else if (size == 4)
		operation_4(la, &lb, 0);
	else if (size == 5)
		operation_5(la, &lb);
	else if (size > 5 && size < 20)
		operation_6_to_20(la, &lb, size);
	else
		operation_x(la, &lb, size);
}

int	main(int argc, char **argv)
{
	t_list	*la;
	int		size;

	la = NULL;
	if (argc == 1)
		return (1);
	if (argc >= 2 && check_argv(argc, argv))
	{
		make_stack(&la, argc, argv);
		size = list_size(&la);
		if (!size)
			return (put_error(), 1);
		if (!check_double(&la))
			return (put_error(), ft_free(&la), 1);
		compression(&la, size);
		if (check_order(size, &la))
			return (ft_free(&la), 0);
		sort_operation(size, &la);
		list_clear(&la);
	}
	else
		return (ft_putstr_fd("Error\n", 1), 1);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }
