/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:13:02 by yotsurud          #+#    #+#             */
/*   Updated: 2024/07/08 14:52:10 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define MANDATORY	1
# define BONUS		2

typedef struct s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	int				num;
	int				index;
}				t_list;

// checks
int		check_argv(int argc, char **argv);
int		check_atoi(char *str);
int		check_number(long nbr);
int		check_order(int size, t_list **la);
int		check_double(t_list **lst);
int		check_index(t_list **lst, int index, int size);
int		is_space(char c);
int		is_sign(char c);
int		is_int(long num);

// make stack
int		set_stack(t_list **la, int argc, char **argv);
int		make_stack(t_list **la, int argc, char **argv);
int		set_new_node(t_list **la, char *str);
void	compression(t_list **la, int size);

// error and free
int		put_error(void);
void	put_bonus_result(t_list **la, t_list **lb, int size);

// list functions
t_list	*list_new(int number);
void	list_add_front(t_list **lst, t_list *new);
void	list_add_last(t_list **lst, t_list *new);
int		list_size(t_list **lst);
void	list_clear(t_list **lst);

// node hundling 
void	func_s(t_list **lst);
void	func_p(t_list **lst1, t_list **lst2);
void	func_r(t_list **lst);
void	func_rr(t_list **lst);

// orders
void	sa(t_list **la, int select);
void	sb(t_list **lb, int select);
void	ss(t_list **la, t_list **lb, int select);
void	pa(t_list **lst1, t_list **lst2, int select);
void	pb(t_list **lst1, t_list **lst2, int select);
void	ra(t_list **la, int select);
void	rb(t_list **lb, int select);
void	rr(t_list **la, t_list **lb, int select);
void	rra(t_list **la, int select);
void	rrb(t_list **lb, int select);
void	rrr(t_list **la, t_list **lb, int select);

// operations
void	sort_operation(int size, t_list **la);
void	operation_3(t_list **la);
void	operation_4(t_list **la, t_list **lb, int index);
void	operation_5(t_list **la, t_list **lb);
void	operation_6_to_20(t_list **la, t_list **lb, int size);

// operation_x
void	operation_x(t_list **la, t_list **lb, int size);
void	operation_pb(t_list **la, t_list **lb, int size, int range);
void	marge_or_not(t_list **la, t_list **lb, int range);
void	rotate_n(t_list **la, t_list **lb, int n);
void	rev_rotate_n(t_list **la, t_list **lb, int n);

// bonus_operation
void	bonus_sort_operation(t_list **la, t_list **lb, char *str);
void	bonus_operation_s(t_list **la, t_list **lb, char *str);
void	bonus_operation_p(t_list **la, t_list **lb, char *str);
void	bonus_operation_r(t_list **la, t_list **lb, char *str);

#endif
