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
 * find max and min elements of the stack_a;
 */

int             find_extremum(t_stack *stack_a, char *str)
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
 * divide stack_a by 3 parts(min->mid->max);
 */

int     find_three_parts_stack_a(int max_in_stack_a, int min_in_stack_a)
{
    return (((max_in_stack_a - min_in_stack_a) / 3));
}

/*
 * push to stack_b elements from stack_a in the oder;
 * first do we find elements from the first part of our future sorted stack;-------------------------------
 */
void            push_stack_b_first_second(t_stack **stack_a, t_stack **stack_b,
                     int min_in_stack_a, int part)
{
    int         border_of_stack_a;
    int         flag;

    flag = 0;
    border_of_stack_a = part;
    // это граница первой части из трех, самые маленькие числа должны входить в этот состав;
    while (*stack_a && flag < 2)
    {
        while ((*stack_a && (*stack_a)->num > border_of_stack_a && flag < 2)
        || ((*stack_a)->num == min_in_stack_a && flag < 2))
        {
            if (*stack_a && (*stack_a)->num == min_in_stack_a)
                flag++;// 1
            if (*stack_a && flag < 2)
                exec_command("ra", stack_a, NULL);
                //ra_rb(stack_a);// выкидываем элементы больше "part_of_stack_a" в конец стека "stack_a"
        }
        while (*stack_a && (*stack_a)->num >= min_in_stack_a
        && (*stack_a)->num <= border_of_stack_a)
        {
            if ((*stack_a)->num == min_in_stack_a)
                exec_command("ra", stack_a, NULL);
//                ra_rb(stack_a);
            else
                exec_command("pb", stack_a, stack_b);
//              pb(stack_a, stack_b);
        }
    }
}

int len_stack(t_stack *stack)
{
    int i = 0;
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return i;
}

void            push_stack_b_three(t_stack **stack_a, t_stack **stack_b,
                                   int min_in_stack_a, int max_in_stack_a)
{
    while (len_stack(*stack_a) > 2)
    {
        if ((*stack_a)->num == min_in_stack_a || (*stack_a)->num == max_in_stack_a)
            exec_command("ra", stack_a, NULL);
            //            ra_rb(stack_a);
        else
            exec_command("pb", stack_a, stack_b);
//        pb(stack_a, stack_b);
    }
}

/*
 * Now we must push numbers in ascending oder  frob stack_b to stack_a;
 */

/*
 * push to stack_b elements from stack_a in the oder;
 * second do we find elements from the second part of our future sorted stack;-------------------------------
 */

void            push_stack_b_second(t_stack **stack_a, t_stack **stack_b,
                             int min_in_stack_a, int find_three_parts)
{
    int     second_border_stack_a;
    int     save_fist_num;
    int     flag;
    int     first_border_stack_a;

    flag = 0;
    save_fist_num = (*stack_a)->num;
    first_border_stack_a = min_in_stack_a + find_three_parts;
    second_border_stack_a = min_in_stack_a + find_three_parts * 2;
    while (*stack_a && flag < 2)
    {
        if ((*stack_a && (*stack_a)->num == save_fist_num) || ((*stack_a)->next->num == save_fist_num))
            flag++; // = 1
        if (*stack_a && (*stack_a)->num > second_border_stack_a)
            exec_command("pb", stack_a, stack_b);
            //            pb(stack_a, stack_b); // 10 to the end
        if (*stack_a && (*stack_a)->num > first_border_stack_a
            && (*stack_a)->num <= second_border_stack_a)
            exec_command("ra", stack_a, NULL);
//            ra_rb(stack_a);
    }
}

int     find_position(t_stack *stack, int min)
{
    int i = 0;
    while (stack)
    {
        if (stack->num == min)
            return i;
        stack = stack->next;
        i++;
    }
    return -1;
}

void    final_sort(t_stack **stack, int len, int min)
{
    int pos;
    pos = find_position(*stack, min);
    if (pos < len / 2) // минимальный элемент в начале
        while (find_position(*stack, min) != 0)
            exec_command("ra", stack, NULL);
    else               // минимальный элемент в конце
        while (find_position(*stack, min) != 0)
            exec_command("rra", stack, NULL);
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
        if (check_ascending_oder(stack_a, stack_b))
        {
            write(1, "OK\n", 3);
            return (0);
        }
        nums->max_in_stack_a = find_extremum(stack_a, "max");
//        printf("max = %d\n", nums->max_in_stack_a);
        nums->min_in_stack_a = find_extremum(stack_a, "min");
        nums->find_three_parts_stack_a = find_three_parts_stack_a(nums->max_in_stack_a, nums->min_in_stack_a);
        push_stack_b_first_second(&stack_a, &stack_b, nums->min_in_stack_a, nums->find_three_parts_stack_a);
        push_stack_b_first_second(&stack_a, &stack_b, nums->min_in_stack_a, nums->find_three_parts_stack_a * 2);
        push_stack_b_three(&stack_a, &stack_b, nums->min_in_stack_a, nums->max_in_stack_a);

        t_stack *tmp_b; // удалить
        tmp_b = stack_b;
        write(1, "stack_b beg:\n", 13);
        while (tmp_b)
        {
            printf("%d, ", tmp_b->num);
            tmp_b = tmp_b->next;
        }
        main_sort(&stack_a, &stack_b);
        final_sort(&stack_a, argc - 1, nums->min_in_stack_a);
//        push_stack_b_second(&stack_a, &stack_b, nums->min_in_stack_a, nums->find_three_parts_stack_a);

        printf("\nstack_a :\n");
        while (stack_a)
        {
            printf("%d, ", stack_a->num);
            stack_a = stack_a->next;
        }
        printf("\n");
//        printf("stack_b :\n");

//        while (stack_b)
//        {
//            printf("%d, ", stack_b->num);
//            stack_b = stack_b->next;
//        }
    }
    return 0;
}
