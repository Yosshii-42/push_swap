/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:44:26 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/28 15:22:57 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = ft_strlen(argv[i]);
		while (argv[i][j] && j < len)
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			if (argv[i][j] && is_sign(argv[i][j]))
				j++;
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j] && !is_space(argv[i][j]))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

void	make_stack(t_list **la, int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			if (argv[i][j] && (is_sign(argv[i][j]) || ft_isdigit(argv[i][j])))
			{
				set_new_node(la, &argv[i][j]);
				j++;
			}
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
}

void	set_new_node(t_list **la, char *str)
{
	long	num;
	t_list	*new;

	num = ft_atol(str);
	new = NULL;
	if (num >= INT_MIN && num <= INT_MAX)
	{
		new = list_new((int)num);
		if (!new)
		{
			ft_error(la);
			return ;
		}
		list_add_last(la, new);
	}
	else
	{
		ft_error(la);
		return ;
	}
}
