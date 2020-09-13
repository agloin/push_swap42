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
#include "../libft/libft.h"

void     exec_command(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strcmp(line, "sa") == 0)
    {
        sa_sb(*stack_a);
        write(1, "sa\n", 3);
    }
    else if (ft_strcmp(line, "sb") == 0)
    {
        sa_sb(*stack_b);
        write(1, "sb\n", 3);
    }
    else if (ft_strcmp(line, "ss") == 0)
    {
        ss(*stack_a, *stack_b);
        write(1, "ss\n", 3);
    }
    else if (ft_strcmp(line, "pa") == 0)
    {
        write(1, "pa\n", 3);
        pa(stack_a, stack_b);
    }
    else if (ft_strcmp(line, "pb") == 0)
    {
        write(1, "pb\n", 3);
        pb(stack_a, stack_b);
    }
    else if (ft_strcmp(line, "ra") == 0)
    {
        ra_rb(stack_a);
        write(1, "ra\n", 3);
    }
    else if (ft_strcmp(line, "rb") == 0)
    {
        write(1, "rb\n", 3);
        ra_rb(stack_b);
    }
    else if (ft_strcmp(line, "rr") == 0)
    {
        write(1, "rr\n", 3);
        rr(stack_a, stack_b);
    }
    else if (ft_strcmp(line, "rra") == 0)
    {
        write(1, "rra\n", 4);
        rra_rrb(stack_a);
    }
    else if (ft_strcmp(line, "rrb") == 0)
    {
        write(1, "rrb\n", 4);
        rra_rrb(stack_b);
    }
    else if (ft_strcmp(line, "rrr") == 0)
    {
        write(1, "rrr\n", 4);
        rrr(stack_a, stack_b);
    }
}
