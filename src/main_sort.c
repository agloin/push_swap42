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

/*
 *      Сортировка основная. Для болшего количества чисел.
 */

#include "../includes/push_swap.h"

void    main_sort(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        if ((*stack_a)->num < (*stack_b)->num &&
        (*stack_a)->next->num > (*stack_b)->num)
        {
            exec_command("ra", stack_a, NULL);
            exec_command("pa", stack_a, stack_b);
        }
        else
        {
            exec_command("ra", stack_a, NULL);
        }
    }
}

//void    sort_for_three(t_stack **stack_a, t_stack **stack_b) {
//    while (*stack_b)
//        pb(stack_a, stack_b);
//    while (*stack_a)
//    {
//    }
//}
