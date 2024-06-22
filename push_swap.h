#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

typedef struct  s_list
{
    struct s_list   *pre;
    struct s_list   *next;
    int             num;
    int             index;
}               t_list;

int	check_argv(int argc, char **argv);
int	check_number(long nbr);
int	is_space(char c);
void	compression(t_list **la, int size);
void	ft_error(t_list **lst);
int	*set_tab(int argc, char **argv, int *tab);
void	make_stack(t_list **la, int argc, char **argv);
int	check_order(int size, t_list **la);
int	check_double(int *tab, int size);

t_list    *list_new(int number);
void    list_add(t_list **lst, t_list *new);
t_list  *list_last(t_list *lst);
int list_size(t_list **lst);
void    list_delone(t_list *lst);
void    list_clear(t_list **lst);

void    list_swap(t_list **lst);
void    list_push(t_list **lst1, t_list **lst2);
void  rotate(t_list **lst);
void  rev_rotate(t_list **lst);
void    sa(t_list **la);
void    sb(t_list **lb);
void    ss(t_list **la, t_list **lb);
void    pa(t_list **lst1, t_list **lst2);
void    pb(t_list **lst1, t_list **lst2);
void    ra(t_list **la);
void    rb(t_list **lb);
void    rr(t_list **la, t_list **lb);
void    rra(t_list **la);
void    rrb(t_list **lb);
void    rrr(t_list **la, t_list **lb);

void    sort_order(int size, t_list **la, t_list **lb);
void    operation_3(t_list **la);
void    operation_4(t_list **la, t_list **lb, int index);
void	operation_5(t_list **la, t_list **lb);
void	operation_x(t_list **la, t_list **lb, int size);
int     find_index(t_list **lst, int index, int size);

#endif