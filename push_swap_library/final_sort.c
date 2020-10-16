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

void	final_sort(t_stack **stack, int len, int min)
{
	int pos;

	pos = find_position(*stack, min);
	if (pos < len / 2)
		while (find_position(*stack, min) != 0)
			exec_command("ra", stack, NULL);
	else
		while (find_position(*stack, min) != 0)
			exec_command("rra", stack, NULL);
}
