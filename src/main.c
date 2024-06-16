#include "../push_swap.h"

void  make_stack(t_list **lst_a, int argc, char **argv)
{
    t_list  *new;

    new = NULL;
    while (argc - 1 > 0)
    {
        new = list_new(ft_atoi(argv[argc - 1]));
        if (!new)
            return ;
        list_add(lst_a, new);
        argc--;
    }
}

int main(int argc, char **argv)
{
    t_list  *la;
    t_list  *lb;
 
    la = NULL;
    lb = NULL;
    if (argc >= 2)
    {
        make_stack(&la, argc, argv);
        if (!la)
            return (1);
        pa(&la, &lb);
        pa(&la, &lb);
        pa(&la, &lb);
        pa(&la, &lb);
        pa(&la, &lb);
        // ss(&la, &lb);
        // ra(&la);
        // rb(&lb);
        // rr(&la, &lb);
        // rra(&la);
        // rrb(&lb);
        rrr(&la, &lb);
        t_list *ptr;
        ptr = la;
        while (la)
        {
            printf("la->num = %d\n", la->num);
            la = la->next;
            if (la == ptr)
                break ;
        }
        ptr = lb;
        while (lb)
        {
            printf("lb->num = %d\n", lb->num);
            lb = lb->next;
            if (lb == ptr)
                break ;
        }
    }
}
