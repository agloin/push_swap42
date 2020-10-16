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

void	sort_three_nums(t_stack **stack_a, t_stack **stack_b)
{
	while (check_ascending_oder(*stack_a, *stack_b) != 1)
	{
		if ((*stack_a) && (*stack_a)->num > (*stack_a)->next->num)
			exec_command("sa", stack_a, stack_b);
		else
			exec_command("rra", stack_a, stack_b);
	}
}
