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

/*
 * ra - все элементы поднимаются на один. второй становится первым
 * первый становится последним.
 */


/*
 * ПЕРЕДЕЛАТЬ ПОД ДВЕ ЗВЕЗДЫ!!!!!!!!!!!!!!!!
 */
void    ra_rb(t_stack  **stack)
{
    if ((*stack) && (*stack)->next)
    {
        t_stack *first_element;
        t_stack *last_element;
        t_stack *second_element;

        first_element = *stack;
        second_element = (*stack)->next;
        while (*stack && (*stack)->next)
            *stack = (*stack)->next;
        last_element = *stack;
        (*stack)->next = first_element;
        first_element->next = NULL;
        *stack = second_element;
    }
}

