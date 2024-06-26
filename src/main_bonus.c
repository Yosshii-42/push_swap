/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:09 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/25 14:26:14 by yotsurud         ###   ########.fr       */
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

void	checker(int size)//, t_list **la, t_list **lb)
{
	char	*command;
	int		i;

	i = 0;
	while (i < size)
	{
		command = get_next_line(0);
		ft_printf("\nchecker\n");
		// if (!command)
		// 	break ;
		ft_printf("%s\n", command);
		free(command);
		i++;
	}
	close(0);
}

int	main(int argc, char **argv)
{
	t_list	*la;
	t_list	*la_cp;
	t_list	*lb;
	int		*tab;
	char	result[128];

	la = NULL;
	lb = NULL;
	tab = NULL;
	if (argc >= 2 && check_argv(argc, argv))
	{
		tab = set_tab(argc, argv, tab);
		if (!tab)
			return (ft_putstr_fd("Error\n", 1), 1);
		make_stack(&la, argc, argv);
		make_stack(&la_cp, argc, argv);
		if (!la)
			return (ft_putstr_fd("Eerror\n", 1), 1);
		compression(&la, argc - 1);
		compression(&la_cp, argc - 1);
		if (check_order(argc - 1, &la))
			return (0);
		sort_operation(argc - 1, &la, &lb);	
		t_list	*ptr = la_cp;
		while (la_cp)
		{
			ft_printf("la_cp->num = %d\n", la_cp->num);
			la_cp = la_cp->next;
			if (la_cp == ptr)
				break;
		}
		// checker(argc - 1);//, &la_cp, &lb);
		read(0, result, 127);
		result[127] = '\0';
		ft_printf("\nafter read\n%s", result);
		free(tab);
		list_clear(&la);
	}
	else
		return (ft_putstr_fd("Error\n", 1), 1);
}
/*
__attribute__((destructor)) static void destructor()
{
    system("leaks -q push_swap");
}
*/
