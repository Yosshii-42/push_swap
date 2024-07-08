/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:47:24 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/06 15:02:09 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_stack(t_list **la, int argc, char **argv)
{
	int	i;

	i = 0;
	if (!make_stack(la, argc, argv))
		return (FALSE);
	else if (!check_double(la))
		return (list_clear(la), FALSE);
	else
		return (TRUE);
}

int	make_stack(t_list **la, int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			if (argv[i][j] && (is_sign(argv[i][j]) || ft_isdigit(argv[i][j])))
			{
				if (!set_new_node(la, &argv[i][j++]))
					return (list_clear(la), FALSE);
			}
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
		}
	}
	return (TRUE);
}

int	set_new_node(t_list **la, char *str)
{
	long	num;
	t_list	*new;

	num = ft_atol(str);
	new = NULL;
	if (is_int(num) == 0)
		return (FALSE);
	else
	{
		new = list_new((int)num);
		if (!new)
			return (list_clear(la), FALSE);
	}
	list_add_last(la, new);
	return (TRUE);
}
