#include "../includes/push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_b)
    {
        t_stack *tmp_a;
        tmp_a = *stack_b;
        
        t_stack *tmp_b;
        tmp_b = (*stack_b)->next;
        
        tmp_a->next = *stack_a;
        
        *stack_a = tmp_a;
        *stack_b = tmp_b;
    }
}
//
//int main(int argc, char ** argv)
//{
//    t_stack *a1;
//    t_stack *a2;
//    t_stack *a3;
//    t_stack *a;
//
//    t_stack *b1;
//    t_stack *b2;
//    t_stack *b3;
//    t_stack *b;
//
//    a1 = (t_stack *)malloc(sizeof(t_stack));
//    a2 = (t_stack *)malloc(sizeof(t_stack));
//    a3 = (t_stack *)malloc(sizeof(t_stack));
//    b1 = (t_stack *)malloc(sizeof(t_stack));
//    b2 = (t_stack *)malloc(sizeof(t_stack));
//    b3 = (t_stack *)malloc(sizeof(t_stack));
//
//    a1->next = a2;
//    a2->next = a3;
//    a3->next = NULL;
//
//    b1->next = b2;
//    b2->next = b3;
//    b3->next = NULL;
//
//    a1->num = 1;
//    a2->num = 3;
//    a3->num = 4;
//
//    b1->num = 10;
//    b2->num = 12;
//    b3->num = 11;
//
//
//
//    a = a1;
//    b = b1;
//    pa(&a1, &b1);
//    printf("\na = ");
//    while (a1)
//    {
//        printf(" %d", a1->num);
//        a1 = a1->next;
//    }
//
//    printf("\nb = ");
//
//    while (b1)
//    {
//        printf(" %d", b1->num);
//        b1 = b1->next;
//    }
//    return (0);
//}



//int main(int argc, char ** argv)
//{
//    t_stack *a1;
//    t_stack *a2;
//    t_stack *a3;
//    t_stack *a;
//
//    t_stack *b1;
//    t_stack *b2;
//    t_stack *b3;
//    t_stack *b;
//
//    a1 = (t_stack *)malloc(sizeof(t_stack));
//    a2 = (t_stack *)malloc(sizeof(t_stack));
//    a3 = (t_stack *)malloc(sizeof(t_stack));
//    b1 = (t_stack *)malloc(sizeof(t_stack));
//    b2 = (t_stack *)malloc(sizeof(t_stack));
//    b3 = (t_stack *)malloc(sizeof(t_stack));
//
//    a1->next = a2;
//    a2->next = a3;
//    a3->next = NULL;
//
//    b1->next = b2;
//    b2->next = b3;
//    b3->next = NULL;
//
//    a1->num = 1;
//    a2->num = 3;
//    a3->num = 4;
//
//    b1->num = 10;
//    b2->num = 12;
//    b3->num = 11;
//
//    a = a1;
//    b = b1;
//
//    printf("stack_a = ");
//    while (a)
//    {
//        printf("%d, ", a->num);
//        a = a->next;
//    }
//    printf("\nstack_b = ");
//    while (b)
//    {
//        printf("%d, ", b->num);
//        b = b->next;
//    }
//
//    t_stack *tmp;
//    pa(&a1, &b1);
//
//    a = a1;
//    b = b1;
//    printf("\nnew_stack_a = ");
//    while(a)
//    {
//        printf("%d, ", a->num);
//        a = a->next;
//    }
//
//    printf("\nnew_stack_b = ");
//    while(b)
//    {
//        printf("%d, ", b->num);
//        b = b->next;
//    }
//    // printf("b = %d\n", b1->num);
//    return 0;
//}