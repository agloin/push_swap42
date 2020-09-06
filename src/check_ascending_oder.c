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

int check_ascending_oder(t_stack *stack, t_stack *stack_b)
{
    while(stack && stack->next)
    {
        if (stack->num > stack->next->num)
            return (0);
        stack = stack->next;
    }
    if (stack_b != NULL)
        return (0);
    return (1);
}
