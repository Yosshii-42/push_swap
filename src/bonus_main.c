/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:28 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/04 14:36:46 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*la;
	t_list	*lb;
	int		size;
	char	*str;

	la = NULL;
	lb = NULL;
	str = NULL;
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
		bonus_sort_operation(&la, &lb, str);
		put_bonus_result(&la, &lb, size);
		return (list_clear(&la), list_clear(&lb), 0);
	}
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q checker");
// }
