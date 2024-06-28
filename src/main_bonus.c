/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:28 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/28 15:23:07 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_operation(int size, t_list **la, t_list **lb)
{
	if (size == 2)
	{
		if ((*la)->index > (*la)->next->index)
			sa(la);
	}
	else if (size == 3)
		operation_3(la);
	else if (size == 4)
		operation_4(la, lb, 0);
	else if (size == 5)
		operation_5(la, lb);
	else if (size > 5 && size < 20)
		operation_6_to_20(la, lb, size);
	else
		operation_x(la, lb, size);
}

int	main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	int		size;

	la = NULL;
	lb = NULL;
	if (argc == 1)
		return (1);
	if (argc >= 2 && check_argv(argc, argv))
	{
		make_stack(&la, argc, argv);
		size = list_size(&la);
		if (!size)
			return (ft_putstr_fd("Eerror\n", 1), 1);
		if (!check_double(&la))
			return (ft_error(&la), 1);
		compression(&la, size);
		if (check_order(size, &la))
			return (0);
		sort_operation(size, &la, &lb);
		list_clear(&la);
	}
	else
		return (ft_putstr_fd("Error\n", 1), 1);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }

	// t_list	*ptr;
	// ptr = *la;
	// while ((*la)->num)
	// {
	// 	ft_printf("%d\n", (*la)->num);
	// 	*la = (*la)->next;
	// 	if (*la == ptr)
	// 		break ;
	// }