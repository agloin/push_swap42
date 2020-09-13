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

/*
 * вять первый элемент из "stack_b" и поместить его в "stack_a"
 */

#include "../includes/push_swap.h"

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_b)
    {
        t_stack *tmp_a;
        t_stack *tmp_b;

        tmp_a = *stack_b; // the first digit of stack "b"
        tmp_b = (*stack_b)->next;
        tmp_a->next = (*stack_a); // pointer to the first dig on stack "a"
        *stack_a = tmp_a;
        *stack_b = tmp_b;
    }
}
