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
 * find max and min elements of the stack_a
 */
int     find_extremum(t_stack *stack_a, char *str)
{
    t_stack *tmp;
    int     num;

    num = stack_a->num;
    if (ft_strcmp(str, "max") == 0)
    {
        while(stack_a)
        {
            if (stack_a->num > num)
                num = stack_a->num;
            stack_a = stack_a->next;
        }
    }
    else if (ft_strcmp(str, "min") == 0)
    {
        while(stack_a)
        {
            if (stack_a->num < num)
                num = stack_a->num;
            stack_a = stack_a->next;
        }
    }
    return (num);
}

/*
 * divide stack_a by 3 part(min->mid->max
 */

int     find_three_parts(int max_in_stack_a, int min_in_stack_a)
{
    return (((max_in_stack_a - min_in_stack_a) / 3));
}

int     find_mid_num(int max_in_stack_a, int min_in_stack_a)
{
    return (((max_in_stack_a + min_in_stack_a) / 2));
}

/*
 * push to stack_b elements from stack_a in the oder;
 * first do we find elements from the first part of our future sorted stack;
 */
void    push_stack_b(t_stack **stack_a, t_stack **stack_b,
                     int min_in_stack_a, int max_in_stack_a, int find_three_parts)
{
//    t_stack *tmp;
    int     part_of_stack_a;

    part_of_stack_a = min_in_stack_a + find_three_parts;
    while (*stack_a)
    {
        if ((*stack_a)->num > min_in_stack_a
        && (*stack_a)->num < part_of_stack_a)
            pb(stack_a, stack_b);
        else
        {
            /*
             * -----------------------------This function-------------------------
             */
            *stack_a = (*stack_a)->next;
        }
    }
}

int     main(int argc, char **argv)
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    t_stack     *tmp_begin;
    num_list    *nums;

    nums = (num_list *)malloc(sizeof(num_list));
    stack_a = NULL;
    stack_b = NULL;
    nums->min_in_stack_a = 0;
    nums->max_in_stack_a = 0;
    if (argc > 1 && is_digit(argv) && is_repeat(argv) == 0)
    {
        fill_stack(&stack_a, argv);
        nums->max_in_stack_a = find_extremum(stack_a, "max");
        nums->min_in_stack_a = find_extremum(stack_a, "min");
        push_stack_b(&stack_a, &stack_b, nums->min_in_stack_a, nums->max_in_stack_a)
        printf("find_three_parts = %d\n", find_three_parts(nums->max_in_stack_a, nums->min_in_stack_a));
//        printf("max elem = %d\nmin ele, = %d\n", nums->max_in_stack_a, nums->min_in_stack_a);
    }
    return 0;
}
