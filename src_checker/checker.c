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
**      Проверяет работу программы "push_swap".
**     Выдает "OK" eсли роограмма отсортировала числа в стеке "a"
**     и стек "b" пустой.
*/

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	char	*line;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc > 1 && is_digit(argv) && is_repeat(argv) == 0)
	{
		fill_stack(&stack_a, argv);
		while (get_next_line(0, &line) > 0)
		{
			if (find_command(line, &stack_a, &stack_b) == 0)
				exit(0);
			free(line);
		}
		if (check_ascending_oder(stack_a, stack_b) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		exit(0);
	}
	return (0);
}
