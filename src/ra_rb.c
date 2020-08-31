#include "../includes/push_swap.h"

/*
 * ra - все элементы поднимаются на один. второй становится первым
 * первый становится последним.
 */

t_stack   *ra_rb(t_stack  *lst)
{
    if (lst && lst->next)
    {
        t_stack *first_elem;
        t_stack *second_elem;
        t_stack *last_elem;

        first_elem = lst;
        second_elem =lst->next;
        while (lst->next)
        {
            lst = lst->next;
        }
        last_elem = lst;
        last_elem->next = first_elem;
        first_elem->next = NULL;
        return (second_elem);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *c;
    t_stack *d;
    t_stack *e;
    t_stack *f;
    t_stack *g;
    t_stack *h;
    t_stack *i;
    t_stack *j;


    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    c = (t_stack *)malloc(sizeof(t_stack));
    e = (t_stack *)malloc(sizeof(t_stack));
    f = (t_stack *)malloc(sizeof(t_stack));
    g = (t_stack *)malloc(sizeof(t_stack));
    h = (t_stack *)malloc(sizeof(t_stack));
    i = (t_stack *)malloc(sizeof(t_stack));
    j = (t_stack *)malloc(sizeof(t_stack));

    a->next = b;
    a->next = NULL;
//    b->next = c;
//    c->next = e;
//    e->next = f;
//    f->next = g;
//    g->next = h;
//    h->next = i;
//    i->next = j;
//    j->next = NULL;

    a->num = 20;
//    b->num = 1;
//    c->num = 0;
//    e->num = 5;
//    f->num = 3;
//    g->num = 4;
//    h->num = 5;
//    i->num = 6;
//    j->num = 7;


    d = ra_rb(a);
    while (d)
    {
        printf("num = %d\n", d->num);
        d = d->next;
    }
    return (0);
}
