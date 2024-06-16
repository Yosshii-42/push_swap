#include "../push_swap.h"

void    sa(t_list **la)
{
    list_swap(la);
}

void    sb(t_list **lb)
{
    list_swap(lb);
}

void    ss(t_list **la, t_list **lb)
{
    list_swap(la);
    list_swap(lb);
}

void    pa(t_list **la, t_list **lb)
{
    list_push(la, lb);
}

void    pb(t_list **lb, t_list **la)
{
    list_push(lb, la);
}
