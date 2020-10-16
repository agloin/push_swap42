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

void	sort_five_nums(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		max;
	int		min;

	max = find_extremum(*stack_a, "max");
	min = find_extremum(*stack_a, "min");
	tmp = NULL;
	while (len_stack(*stack_a) > 3)
	{
		if ((*stack_a)->num == max || (*stack_a)->num == min)
			exec_command("pb", stack_a, stack_b);
		else
			exec_command("ra", stack_a, stack_b);
	}
	sort_three_nums(stack_a, &tmp);
	while (*stack_b)
	{
		if ((*stack_b)->num == max)
		{
			exec_command("pa", stack_a, stack_b);
			exec_command("ra", stack_a, stack_b);
		}
		else
			exec_command("pa", stack_a, stack_b);
	}
}
