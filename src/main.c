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
    t_list  *lst_a;
    t_list  *lst_b;
 
    lst_a = NULL;
    lst_b = NULL;
    if (argc >= 2)
    {
        make_stack(&lst_a, argc, argv);
        if (!lst_a)
            return (1);
        pa(&lst_a, &lst_b);
        pa(&lst_a, &lst_b);
        pa(&lst_a, &lst_b);
        pa(&lst_a, &lst_b);
        pa(&lst_a, &lst_b);
        pa(&lst_a, &lst_b);
        // pb(&lst_b, &lst_a);
        // pb(&lst_b, &lst_a);
        // pa(&lst_a, &lst_b);
        // pa(&lst_a, &lst_b);
        // rotate(&lst_b);
        // rotate(&lst_b);
        // rev_rotate(&lst_a);
        // list_swap(&lst_b);
        // list_swap(&lst_a);
        // ss(&lst_a, &lst_b);
        rrr(&lst_a, &lst_b);
        t_list *ptr;
        ptr = lst_a;
        while (lst_a)
        {
            printf("lst_a->num = %d\n", lst_a->num);
            lst_a = lst_a->next;
            if (lst_a == ptr)
                break ;
        }
        ptr = lst_b;
        while (lst_b)
        {
            printf("lst_b->num = %d\n", lst_b->num);
            lst_b = lst_b->next;
            if (lst_b == ptr)
                break ;
        }
    }
}
