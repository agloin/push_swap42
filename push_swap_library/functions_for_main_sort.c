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
**      Сортировка основная. Для болшего количества чисел.
*/

#include "../includes/push_swap.h"

int		len_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int		find_place_to_paste(t_stack *stack, int num)
{
	int i;

	i = 0;
	if (num < stack->num)
	{
		while (stack && num < stack->num)
		{
			stack = stack->next;
			i++;
		}
	}
	while (stack && num > stack->num)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int		find_last_elem(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

/*
** находит позицию числа с минимальным количеством операций
** для перемещения его в из stack_b в stack_a
*/

int		find_min_operation_in_stack_b(t_stack *stack_a,
										t_stack *stack_b)
{
	int count;
	int current_pos;
	int min;
	int num;

	count = 0;
	while (stack_b)
	{
		current_pos = find_place_to_paste(stack_a, stack_b->num);
		if (current_pos > len_stack(stack_a) / 2)
			current_pos = len_stack(stack_a) - current_pos - 1;
		current_pos += count;
		if (count == 0 || current_pos < min)
		{
			num = stack_b->num;
			min = current_pos;
		}
		stack_b = stack_b->next;
		count++;
	}
	return (num);
}

void	rotate_b(t_stack **stack_b, int actual_num)
{
	int find_pos;

	find_pos = find_position(*stack_b, actual_num);
	while ((*stack_b)->num != actual_num)
	{
		if (find_pos > len_stack(*stack_b) / 2)
		{
			exec_command("rrb", NULL, stack_b);
		}
		else
			exec_command("rb", NULL, stack_b);
	}
}
