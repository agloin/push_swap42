
#include "../includes/push_swap.h"
#include <stdio.h>


int    is_digit(char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
//        printf("argv[1] = %s\n", argv[i]);
        if (ft_isdigit(*argv[i]) == 0)
        {
            printf("Error\n");
            return (0);
        }
        else
        {
            /*
             * проверка на MAX_INT (long    ft_atoi(char *str)
             */
            if (!(ft_atoi(argv[i]) >= -2147483648 && ft_atoi(argv[i]) <= 2147483647))
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
    if (is_digit(argv) == 1) // if there are all numbers, in argv
    {
        int i;
        int j;

        i = 1;
        while (argv[i])
        {
            j = i + 1;
            while (argv[j])
            {
                if (argv[i] == argv[j])
                {
                    write(1, "Error\n", 6);
                    return (1);
                }
                printf("argv[i] = %s\nargv[j] = %s\n", argv[i], argv[j]);
                j++;
            }
            i++;
        }
    }
    return (0);
}

//void		ft_stack_add(t_stack **alst, t_stack *new)
//{
//    new->next = *alst;
//    *alst = new;
//}
//
//t_stack     *ft_new_stack(int num)
//{
//    t_stack     *tmp;
//
//    if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
//        return (NULL);
//    if (!num)
//        return (NULL);
//    tmp->num = num;
//    return (tmp);
//}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc > 1)
    {
        printf("is_repeat = %d\nis_digit = %d\n", is_repeat(argv), is_digit(argv));
        t_stack *tmp;

        tmp = ft_lst_new(argv);
        if (is_digit(argv) == 1 && is_repeat(argv) == 0)
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

