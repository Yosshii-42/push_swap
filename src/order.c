#include "../push_swap.h"

void    ss(t_list **lst_a, t_list **lst_b)
{
    list_swap(lst_a);
    list_swap(lst_b);
}

void    rr(t_list **lst_a, t_list **lst_b)
{
    rotate(lst_a);
    rotate(lst_b);
}

void    rrr(t_list **lst_a, t_list **lst_b)
{
    rev_rotate(lst_a);
    rev_rotate(lst_b);
}

void    pa(t_list **lst_a, t_list **lst_b)
{
    list_push(lst_a, lst_b);
}

void    pb(t_list **lst_b, t_list **lst_a)
{
    list_push(lst_b, lst_a);
}