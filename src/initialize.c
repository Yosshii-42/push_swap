/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:44:26 by yotsurud          #+#    #+#             */
/*   Updated: 2024/06/26 14:49:17 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			if (argv[i][j] && (argv[i][j] == '-' || argv[i][j] == '+'))
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

int	*set_tab(int argc, char **argv, int *tab)
{
	int		i;
	long	num;

	i = 0;
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

int	make_stack(t_list **la, int argc, char **argv)
{
	t_list	*new;
	int		i;
	int		j;
	int		count;
	long	num;

	new = NULL;
	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			if (argv[i][j] && (is_sign(argv[i][j]) || ft_isdigit(argv[i][j])))
			{
				num = ft_atol(&argv[i][j]);
				if (check_number(num))
				{
					new = list_new((int)num);
					if (!new)
					{
						ft_error(la);
						return (0);
					}
					list_add(la, new);
					count++;
				}
			}
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;		
		}
		i++;
	}
	return (count);
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
