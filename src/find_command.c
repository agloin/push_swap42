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
 *  Фунция проверяет, какие команды делает push_swap и что он подает в checker
 */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int     find_command(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strcmp(line, "sa") == 0)
        sa_sb(*stack_a);
    else if (ft_strcmp(line, "sb") == 0)
        sa_sb(*stack_b);
    else if (ft_strcmp(line, "ss") == 0)
        ss(*stack_a, *stack_b);
    else if (ft_strcmp(line, "pa") == 0)
        pa(stack_a, stack_b);
    else if (ft_strcmp(line, "pb") == 0)
        pb(stack_a, stack_b);
    else if (ft_strcmp(line, "ra") == 0)
        ra_rb(stack_a);
    else if (ft_strcmp(line, "rb") == 0)
        ra_rb(stack_b);
    else if (ft_strcmp(line, "rr") == 0)
        rr(stack_a, stack_b);
    else if (ft_strcmp(line, "rra") == 0)
        rra_rrb(stack_a);
    else if (ft_strcmp(line, "rrb") == 0)
        rra_rrb(stack_b);
    else if (ft_strcmp(line, "rrr") == 0)
        rrr(stack_a, stack_b);
    else
    {
        write(1, "Error\n", 6);
        return (0);
    }
    return (1);
}
