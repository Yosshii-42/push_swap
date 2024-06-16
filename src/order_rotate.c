#include "../push_swap.h"

void    ra(t_list **la)
{
    rotate(la);
}

void    rb(t_list **lb)
{
    rotate(lb);
}

void    rr(t_list **la, t_list **lb)
{
    rotate(la);
    rotate(lb);
}
