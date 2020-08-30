
#include "push_swap.h"
#include <stdio.h>

int    is_digit(char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        if (ft_isdigit(*argv[i] != 0))
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
 * check fo repeat
 */

int     is_repeat(char **argv)
{
    if (is_digit(argv) == 1)
    {
        int i;
        int j;

        j = 2;
        i = 1;
        while (argv[i])
        {
            while (argv[j])
            {
                if (argv[i] == argv[j])
                {
                    write(1, "Error\n", 6);
                    return (0);
                }
                j++;
            }
            i++;
        }
    }
    return (1);
}

void		ft_stack_add(t_stack **alst, t_stack *new)
{
    new->next = *alst;
    *alst = new;
}

t_stack     *ft_new_stack(int num)
{
    t_stack     *tmp;

    if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    if (!num)
        return (NULL);
    tmp->num = num;
    return (tmp);
}

int main(int argc, char **argv)
{
    t_stack     *a;
    int i;

    a = NULL;
    i = 1;

    while (i != argc)
    {
        t_stack *tmp;
        int num;

        num =  (int)ft_atoi(argv[i]);
        tmp = ft_new_stack(num);
        ft_stack_add(&a, tmp);
        printf("%d\n", a->num);
        i++;
    }
    return(0);
}

