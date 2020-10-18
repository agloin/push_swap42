/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:22:23 by agloin            #+#    #+#             */
/*   Updated: 2020/10/16 16:49:16 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** push to stack_b elements from stack_a in the oder;
** first do we find elements from the first part of our future sorted stack;
** part_of_stack - одна из частей стека, значение одной части мы получаем
** из функции "one_part_stack_a"
*/

void	push_stack_b_first_second(t_stack **stack_a, t_stack **stack_b,
	int min_in_stack_a, int part_of_stack)
{
	int border_of_stack_a;
	int flag;

	flag = 0;
	border_of_stack_a = part_of_stack;
	while (*stack_a && flag < 2)
	{
		while ((*stack_a && (*stack_a)->num > border_of_stack_a && flag < 2)
		|| ((*stack_a)->num == min_in_stack_a && flag < 2))
		{
			if (*stack_a && (*stack_a)->num == min_in_stack_a)
				flag++;
			if (*stack_a && flag < 2)
				exec_command("ra", stack_a, NULL);
		}
		while (*stack_a && (*stack_a)->num >= min_in_stack_a
			&& (*stack_a)->num <= border_of_stack_a)
		{
			if ((*stack_a)->num == min_in_stack_a)
				exec_command("ra", stack_a, NULL);
			else
				exec_command("pb", stack_a, stack_b);
		}
	}
}

void	push_stack_b_three(t_stack **stack_a, t_stack **stack_b,
						int min_in_stack_a, int max_in_stack_a)
{
	while (len_stack(*stack_a) > 2)
	{
		if ((*stack_a)->num == min_in_stack_a
		|| (*stack_a)->num == max_in_stack_a)
			exec_command("ra", stack_a, NULL);
		else
			exec_command("pb", stack_a, stack_b);
	}
}

void	main_simplify2(int max, int min,
				t_stack **stack_a,
				t_stack **stack_b)
{
	int one_part_stack;

	one_part_stack = one_part_stack_a(find_extremum(*stack_a, "max"),
								find_extremum(*stack_a, "min"));
	push_stack_b_first_second(stack_a, stack_b, min, one_part_stack);
	push_stack_b_first_second(stack_a, stack_b, min, one_part_stack * 2);
	push_stack_b_three(stack_a, stack_b, min, max);
	main_sort(stack_a, stack_b);
}

/*
** Now we must push numbers in ascending oder  from stack_b to stack_a;
*/

void	main_simplify1(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (len_stack(*stack_a) == 2)
		exec_command("ra", stack_a, stack_b);
	else if (len_stack(*stack_a) == 3)
		sort_three_nums(stack_a, stack_b);
	else if (len_stack(*stack_a) == 5)
		sort_five_nums(stack_a, stack_b);
	else
	{
		main_simplify2(find_extremum(*stack_a, "max"),
					find_extremum(*stack_a, "min"), stack_a, stack_b);
		final_sort(stack_a, argc - 1, find_extremum(*stack_a, "min"));
	}
}

int		main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1 && is_digit(argv) && is_repeat(argv) == 0)
	{
		fill_stack(&stack_a, argv);
		if (check_ascending_oder(stack_a, stack_b))
			exit(0);
		main_simplify1(&stack_a, &stack_b, argc);
	}
	clean_memory(&stack_a, &stack_b);
	return (0);
}
