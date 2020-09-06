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

t_stack     *ft_lst_new(char **str)
{
    t_stack *lst;
    t_stack *begin;
    int i = 1;
    long str_tmp;

    lst = (t_stack *)malloc(sizeof(t_stack));
    begin = lst;
    while (str[i])
    {
        str_tmp = ft_atoi(str[i]);
        lst->num = (int)str_tmp;
        if (str[i + 1])
        {
            lst->next = (t_stack *)malloc(sizeof(t_stack));
            lst = lst->next;
        }
        i++;
    }
    lst->next = (t_stack *)malloc(sizeof(t_stack));
    lst->next = NULL;
    return (begin);
}

/*
 * int main(int argc, char **argv)
{
    if (argc > 1)
    {
        t_stack *lst;

        lst = ft_lst_new(argv);
        while(lst)
        {
            printf("lst = %d\n", lst->num);
            lst = lst->next;
        }
    }
    return (0);
}
 */
