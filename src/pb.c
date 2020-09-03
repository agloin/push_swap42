/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:07:12 by agloin            #+#    #+#             */
/*   Updated: 2020/09/03 15:07:14 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * вять первый элемент из "stack_a" и поместить его в "stack_b"
 */
void    pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;

    tmp_b = *stack_a; // push the first elem of stack "a" into stack "b"
    tmp_a = (*stack_a)->next; // now stack "a" begin from second elem
    tmp_b->next = (*stack_b); // the new first elemennt point to the old first element

    *stack_b = tmp_b;
    *stack_a = tmp_a;
}

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
//    pb(&a1, &b1);
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