/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:28 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/04 14:37:55 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*la;
	int		size;

	la = NULL;
	if (argc == 1)
		return (1);
	if (argc >= 2)
	{
		if (!check_argv(argc, argv))
			return (put_error(), 1);
		if (!set_stack(&la, argc, argv))
			return (put_error(), 1);
		size = list_size(&la);
		compression(&la, size);
		if (check_order(size, &la))
			return (list_clear(&la), 0);
		sort_operation(size, &la);
		return (list_clear(&la), 0);
	}
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }
