/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:03:42 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/16 20:11:10 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (is_space(argv[i][j]))
			j++;
		if (argv[i][j] == '-' || ft_isdigit(argv[i][j]))
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*set_tab(int argc, char **argv, int *tab)
{
	int		i = 0;
	long	num;

	tab = (int *)malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (NULL);
	while (i + 1 < argc)
	{
		num = ft_atol(argv[i + 1]);
		if (num < INT_MIN || num > INT_MAX)
			return (free(tab), NULL);
		tab[i] = num;
		i++;
	}
	if (!check_double(tab, i))
		return (free(tab), NULL);
	return (tab);
}

void	make_stack(t_list **la, int argc, char **argv)
{
	t_list	*new;

	new = NULL;
	while (argc - 1 > 0)
	{
		if (check_number(ft_atol(argv[argc - 1])))
		{
			new = list_new(ft_atol(argv[argc - 1]));
			if (!new)
			{
				ft_error(la);
				return ;
			}
		}
		else
		{
			ft_error(la);
			return ;
		}
		list_add(la, new);
		argc--;
	}
}

void	compression(t_list **la, int size)
{
	t_list	*i;
	t_list	*j;
	int		size_i;
	int		size_j;

	i = *la;
	size_i = 0;
	while (size_i < size)
	{
		j = (*la)->pre;
		size_j = 0;
		while (size_j < size)
		{
			if (i->num > j->num)
				(i->index)++;
			j = j->next;
			size_j++;
		}
		i = i->next;
		size_i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	int		*tab;

	la = NULL;
	lb = NULL;
	tab = NULL;
	if (argc >= 2 && check_argv(argc, argv))
	{
		tab = set_tab(argc, argv, tab);
		if (!tab)
			return (ft_putstr_fd("Error\n", 1), 1);
		make_stack(&la, argc, argv);
		if (!la)
			return (ft_putstr_fd("Eerror\n", 1), 1);
		compression(&la, argc - 1);
		if (check_order(argc - 1, &la))
			return (0);
		sort_order(argc - 1, &la, &lb);
		// pb(&la, &lb);
		// pa(&la, &lb);
		// ss(&la, &lb);
		// ra(&la);
		// rb(&lb);
		// rr(&la, &lb);
		// rra(&la);
		// rrb(&lb);
		// rrr(&la, &lb);
		// t_list	*ptr;
		// ptr = la;
		// while (la)
		// {
		// 	printf("la->num = %d, la->index = %d\n", la->num, la->index);
		// 	la = la->next;
		// 	if (la == ptr)
		// 		break ;
		// }
		// ptr = lb;
		// printf("\n");
		// while (lb)
		// {
		// 	printf("lb->num = %d lb->index = %d\n", lb->num, lb->index);
		// 	lb = lb->next;
		// 	if (lb == ptr)
		// 		break ;
		// }
	}
	else
		return (ft_putstr_fd("Error\n", 1) , 1);
	free(tab);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }