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

t_list    *list_new(int number);
void    list_add(t_list **lst, t_list *new);
t_list  *list_last(t_list *lst);
int list_size(t_list **lst);
void    list_delone(t_list *lst);
void    list_clear(t_list **lst, void (*del)(void*));
void    list_swap(t_list **lst);
void    list_push(t_list **lst1, t_list **lst2);
void  rotate(t_list **lst);
void  rev_rotate(t_list **lst);
void    sa(t_list **la);
void    sb(t_list **lb);
void    ss(t_list **la, t_list **lb);
void    pa(t_list **la, t_list **lb);
void    pb(t_list **la, t_list **lb);
void    ra(t_list **la);
void    rb(t_list **lb);
void    rr(t_list **la, t_list **lb);
void    rra(t_list **la);
void    rrb(t_list **lb);
void    rrr(t_list **la, t_list **lb);


#endif