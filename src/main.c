/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:28 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/26 15:39:52 by yotsurud         ###   ########.fr       */
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
	int		*tab;
	int		size;

	la = NULL;
	lb = NULL;
	tab = NULL;
	if (argc >= 2 && check_argv(argc, argv))
	{
		// tab = set_tab(argc, argv, tab);
		// if (!tab)
		// 	return (ft_putstr_fd("Error\n", 1), 1);
		size = make_stack(&la, argc, argv);
		if (!size)
			return (ft_putstr_fd("Eerror\n", 1), 1);
		compression(&la, size);
		// t_list *ptr;
		// ptr = la;
		// while (la->next)
		// {
		// 	ft_printf("num = %d\n", la->num);
		// 	la = la->next;
		// 	if (la == ptr)
		// 		break;
		// }
		if (check_order(size, &la))
			return (0);
		sort_operation(size, &la, &lb);
		t_list *ptr;
		ptr = la;
		while (la->next)
		{
			ft_printf("num = %d\n", la->num);
			la = la->next;
			if (la == ptr)
				break;
		}
		free(tab);
		list_clear(&la);
	}
	else if (argc == 1)
		return (0);
	else
		return (ft_putstr_fd("Error\n", 1), 1);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }

