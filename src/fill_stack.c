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

void fill_stack(t_stack **stack_a, char **argv)
{
    t_stack *begin;
    begin = NULL;
    int i = 2;

    (*stack_a) = (t_stack *)malloc(sizeof(t_stack));
    (*stack_a)->num = (int)ft_atoi(argv[1]);
    begin = (*stack_a);

    while (argv[i])
    {
        int num;

        num = (int)ft_atoi(argv[i]);
        (*stack_a)->next = (t_stack *)malloc(sizeof(t_stack));
        (*stack_a) = (*stack_a)->next;
        (*stack_a)->num = num;
        i++;
    }
    (*stack_a)->next = NULL;
    (*stack_a) = begin;
}
