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

/*
** find max and min elements of the stack_a;
*/

int		find_extremum(t_stack *stack_a, char *str)
{
	int	num;

	num = stack_a->num;
	if (ft_strcmp(str, "max") == 0)
	{
		while (stack_a)
		{
			if (stack_a->num > num)
				num = stack_a->num;
			stack_a = stack_a->next;
		}
	}
	else if (ft_strcmp(str, "min") == 0)
	{
		while (stack_a)
		{
			if (stack_a->num < num)
				num = stack_a->num;
			stack_a = stack_a->next;
		}
	}
	return (num);
}
