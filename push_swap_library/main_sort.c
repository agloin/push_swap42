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
**  Сортировка основная. Для болшего количества чисел.
*/

#include "../includes/push_swap.h"

void	simplify_main_sort(t_stack **stack_a, t_stack **stack_b)
{
	int pos;
	int len;
	int actual_num;

	actual_num = find_min_operation_in_stack_b(*stack_a, *stack_b);
	rotate_b(stack_b, actual_num);
	pos = find_place_to_paste(*stack_a, (*stack_b)->num);
	len = len_stack(*stack_a) / 2;
	if ((*stack_a)->num > (*stack_b)->num
		&& (*stack_b)->num > find_last_elem(*stack_a))
		exec_command("pa", stack_a, stack_b);
	else if (pos > len)
		exec_command("rra", stack_a, NULL);
	else
		exec_command("ra", stack_a, NULL);
}

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_a)->num > (*stack_b)->num &&
							(*stack_b)->num > find_last_elem(*stack_a))
			exec_command("pa", stack_a, stack_b);
		else
			simplify_main_sort(stack_a, stack_b);
	}
}
