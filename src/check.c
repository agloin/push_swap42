#include "../includes/push_swap.h"

/*
 * Begin of validation
 */

/*
 * check for digit
 */
int    is_digit(char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        if (ft_isdigit_str(argv[i]) == 0)
        {
            write(1, "Error\n", 6);
            return (0);
        }
        else
        {
            if (ft_strlen(argv[i]) > 11 || ft_atoi(argv[i]) < -2147483648 ||
                ft_atoi(argv[i]) > 2147483647) // можно проверить на количество символов, чтобы оно не превышало 10 шт
            {
                write(1, "Error\n", 6);
                return (0);
            }
        }
        i++;
    }
    return (1);
}

/*
 * check fo duplicate
 */

int     is_repeat(char **argv)
{
    if (is_digit(argv) != 1)
        return (1);
    else if (is_digit(argv) == 1)// if there are all numbers, of argv
    {
        int i;
        int j;

        i = 1;
        while (argv[i])
        {
            j = i + 1;
            while (argv[j])
            {
                if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                {
                    write(1, "Error\n", 6);
                    return (1);
                }
                j++;
            }
            i++;
        }
    }
    return (0);
}

int check_ascending_oder(t_stack *stack, t_stack *stack_b)
{
    while(stack && stack->next)
    {
        if (stack->num > stack->next->num)
            return (0);
        stack = stack->next;
    }
    if (stack_b != NULL)
        return (0);
    return (1);
}

void fill_stack(t_stack **stack_a, char **argv)
{
    t_stack *begin;
    begin = NULL;
    int i = 2;

    (*stack_a) = (t_stack *)malloc(sizeof(t_stack));
    (*stack_a)->num = (int)ft_atoi(argv[1]);
        begin = (*stack_a);

        while (argv[i])
        {
            int num;

            num = (int)ft_atoi(argv[i]);
            (*stack_a)->next = (t_stack *)malloc(sizeof(t_stack));
            (*stack_a) = (*stack_a)->next;
            (*stack_a)->num = num;
            i++;
        }
        (*stack_a)->next = NULL;
        (*stack_a) = begin;
//        printf("stack filled\n");
}

int main(int argc, char **argv)
{
    char *line;
    t_stack *stack_a;
//    t_stack *begin;
    t_stack *stack_b;

    stack_b = NULL;
    stack_a = NULL;
//    begin = NULL;

//    int i;
//    i = 2;
//
    if (argc > 1 && is_digit(argv) && is_repeat(argv) == 0)
    {
        fill_stack(&stack_a, argv);

        t_stack *tmp;
        tmp = stack_a;

//        printf("filled stack_a is:\n");
//        while (tmp)
//        {
//            ft_putnbr(tmp->num);
//            write(1, " ", 1);
//            tmp = tmp->next;
//        }
//        tmp = stack_a;

        /*
         * NEED SOME CHECK HERE. We must create stack_b and can push it;
         */

        while (get_next_line(0, &line) > 0)
        {
            if (find_command(line, &stack_a, &stack_b) == 0)
                return (0);
            write(1, "stack_a: ", 9);
            tmp = stack_a;
            if (!tmp)
                write(1, "null", 4);
            while (tmp)
            {
                ft_putnbr(tmp->num);
                write(1, " ", 1);
                tmp = tmp->next;
            }

            write(1, "\n", 1);
            write(1, "stack_b: ", 9);
            tmp = stack_b;
            if (!tmp)
                write(1, "null", 4);
            while (tmp)
            {
                ft_putnbr(tmp->num);
                write(1, " ", 1);
                tmp = tmp->next;
            }
            write(1, "\n", 1);
        }
        if (check_ascending_oder(stack_a, stack_b) == 1)
            write(1, "OK\n", 3);
        else
            write(1, "KO\n", 3);
    }
    return(0);
}
