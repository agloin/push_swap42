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
** take the first elem of "stack_a" and push it into "stack_b" at the first
** place
*/

#include "../includes/push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	if (*stack_a)
	{
		tmp_b = *stack_a;
		tmp_a = (*stack_a)->next;
		tmp_b->next = (*stack_b);
		*stack_b = tmp_b;
		*stack_a = tmp_a;
	}
}
