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