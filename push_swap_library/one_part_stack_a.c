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
**    divide stack_a by 3 equal parts(min->mid->max);
*/

int		one_part_stack_a(int max_in_stack_a, int min_in_stack_a)
{
	if (max_in_stack_a < 0 && min_in_stack_a < 0)
		return (min_in_stack_a + (max_in_stack_a - min_in_stack_a) / 3);
	else if (max_in_stack_a > 0 && min_in_stack_a > 0)
		return (((max_in_stack_a - min_in_stack_a) / 3));
	else if ((max_in_stack_a > 0 && min_in_stack_a < 0)
				&& (-(max_in_stack_a / 2) > min_in_stack_a))
		return ((-(max_in_stack_a - min_in_stack_a) / 3));
	else
		return (((max_in_stack_a - min_in_stack_a) / 3));
}
