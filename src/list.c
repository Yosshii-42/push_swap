#include "../push_swap.h"

t_list    *list_new(int number)
{
    t_list  *new;

    // if (!number)
    //     return (NULL);
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->num = number;
    new->index = -1;
    new->pre = NULL;
    new->next = NULL;
    return (new);
}

void    list_add(t_list **lst, t_list *new)
{
    t_list  *last;

    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
        new->next = new;
        new->pre = new;
    }
    else
    {
        last = (*lst)->pre;
        last->next = new;
        (*lst)->pre = new;
        new->pre = last;
        new->next = (*lst);
        *lst = new;
    }
}

t_list  *list_last(t_list *lst)
{
    t_list  *first;

    if (!lst)
        return (NULL);
    first = lst;
    while (lst->next)
    {
        lst = lst->next;
        if (lst == first)
            break;
    }
    return (lst);
}

int list_size(t_list **lst)
{
    t_list  *ptr;
    int     i;

    if (!lst || !(*lst))
        return (0);
    ptr = *lst;
    i = 0;
    while (*lst)
    {
        i++;
        *lst = (*lst)->next;
        if (*lst == ptr)
            break ;
    }
    return (i);
}

void    list_delone(t_list *lst)
{
    if (!lst)
        return ;
    lst->num = 0;
    lst->index = 0;
    lst->pre = NULL;
    free(lst);
    lst = NULL;
}

void    list_clear(t_list **lst, void (*del)(void*))
{
    t_list *ptr;

    if (!lst || !del || !(*lst))
        return ;
    while (*lst)
    {
        ptr = (*lst)->next;
        del(*lst);
        *lst = ptr;
    }
    lst = NULL;
}
