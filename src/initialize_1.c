/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:44:26 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/28 17:52:37 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			ft_free(la);
			return ;
		}
		list_add_last(la, new);
	}
	else
	{
		ft_free(la);
		return ;
	}
}

int	check_double(t_list **la)
{
	t_list	*i;
	t_list	*j;
	int		count;

	i = *la;
	while (1)
	{
		count = 0;
		j = *la;
		while (1)
		{
			if (i->num == j->num)
				count++;
			j = j->next;
			if (j == *la)
				break ;
		}
		if (count > 1)
			return (FALSE);
		i = i->next;
		if (i == *la)
			break ;
	}
	return (TRUE);
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
