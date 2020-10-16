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

int		clean_stack(t_stack **stack)
{
	if (*stack)
	{
		while (*stack)
		{
			free(*stack);
			*stack = (*stack)->next;
		}
		if (*stack == NULL)
			return (1);
	}
	return (0);
}

int		clean_memory(t_stack **stack_a, t_stack **stack_b)
{
	if (clean_stack(stack_a) == 1 && clean_stack(stack_b) == 1)
		return (1);
	return (0);
}
