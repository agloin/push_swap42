#include "../includes/push_swap.h"


void     sa(t_stack *lst)
{
    ft_swap_int(&lst->num, &lst->next->num);
}

//int main(int argc, char **argv)
//{
//    t_stack *a;
//    t_stack *b;
//    t_stack *c;
//
//    a = (t_stack *)malloc(sizeof(t_stack));
//    b = (t_stack *)malloc(sizeof(t_stack));
//    c = (t_stack *)malloc(sizeof(t_stack));
//
//    a->next = b;
//    b->next = c;
//    c->next = NULL;
//
//    a->num = 20;
//    b->num = 1;
//    c->num = 0;
//
//    sa(a);
//    while (a)
//    {
//        printf("num = %d\n", a->num);
//        a = a->next;
//    }
//
//}