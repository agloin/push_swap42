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
** ra - все элементы поднимаются на один. второй становится первым
** первый становится последним.
*/

#include "../includes/push_swap.h"

void	ra_rb(t_stack **stack)
{
	t_stack *first_element;
	t_stack *second_element;

	if ((*stack) && (*stack)->next)
	{
		first_element = *stack;
		second_element = (*stack)->next;
		while (*stack && (*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = first_element;
		first_element->next = NULL;
		*stack = second_element;
	}
}
