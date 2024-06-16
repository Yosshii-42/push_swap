#include "../push_swap.h"

void    rra(t_list **la)
{
    rev_rotate(la);
}

void    rrb(t_list **lb)
{
    rev_rotate(lb);
}

void    rrr(t_list **la, t_list **lb)
{
    rev_rotate(la);
    rev_rotate(lb);
}
