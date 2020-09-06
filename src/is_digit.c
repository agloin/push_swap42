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
