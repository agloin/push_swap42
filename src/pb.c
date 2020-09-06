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
    if (*stack_a)
    {
        t_stack *tmp_a;
        t_stack *tmp_b;

        tmp_b = *stack_a; // push the first elem of stack "a" into stack "b"
        tmp_a = (*stack_a)->next; // now stack "a" begin from second elem
        tmp_b->next = (*stack_b); // the new first elemennt point to the old first element
        *stack_b = tmp_b;
        *stack_a = tmp_a;
    }
}