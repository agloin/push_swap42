/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:22:23 by agloin            #+#    #+#             */
/*   Updated: 2019/09/23 18:25:43 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    rra_rrb(t_stack **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stack *first_element;
        t_stack *predpos;
        t_stack *last_elem;

        first_element = *stack;
        while ((*stack)->next && (*stack)->next->next) // predposl element
            (*stack) = (*stack)->next;
        predpos = *stack;
        last_elem = (*stack)->next;
        last_elem->next = first_element;
        predpos->next = NULL;
        *stack = last_elem;
    }
}
