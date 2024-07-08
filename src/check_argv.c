/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:44:21 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/06 15:24:06 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_argv(int i, char **argv)
{
	int	count;
	int	j;

	while (--i > 0)
	{
		if (!argv[i][0])
			return (FALSE);
		j = 0;
		count = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && is_space(argv[i][j]))
				j++;
			if (argv[i][j] && (is_sign(argv[i][j]) || ft_isdigit(argv[i][j])))
				count += check_atoi(&argv[i][j]);
			if (is_sign(argv[i][j]))
				j++;
			while (argv[i][j] && ft_isdigit(argv[i][j]))
				j++;
			if ((argv[i][j] && !is_space(argv[i][j])) || !count)
				return (FALSE);
		}
	}
	return (TRUE);
}

int	check_atoi(char *str)
{
	if (is_int(ft_atol(str)))
		return (TRUE);
	else
		return (FALSE);
}
