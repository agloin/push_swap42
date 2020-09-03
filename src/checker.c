
#include "../includes/push_swap.h"
#include <stdio.h>


int    is_digit(char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        if (ft_isdigit_str(argv[i]) == 0) //эта паскуда проверяет только положительные числа в строке
        {
//            printf("1111111\n");
            printf("Error\n");
            return (0);
        }
        else
        {
            if (ft_strlen(argv[i]) > 11 || ft_atoi(argv[i]) < -2147483648 ||
                  ft_atoi(argv[i]) > 2147483647) // можно проверить на количество символов, чтобы оно не превышало 10 шт
            {
                printf("Error\n");
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
    else if (is_digit(argv) == 1)// if there are all numbers, in argv
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

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc > 1)
    {
//        printf("is_repeat = %d\nis_digit = %d\n", is_repeat(argv), is_digit(argv));
        t_stack *tmp;

        tmp = ft_lst_new(argv);
        if (is_repeat(argv) == 0)
        {
            while (tmp)
            {
                printf("%d\n", tmp->num);
                tmp = tmp->next;
            }
        }
    }
    return(0);
}

