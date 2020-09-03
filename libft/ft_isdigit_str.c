/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agloin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:23:23 by agloin            #+#    #+#             */
/*   Updated: 2019/09/16 20:27:20 by agloin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isdigit_str(char *str)
{
    int i;

    i = 0;

    if (ft_strlen(str) > 1 && str[i] == '-')
    {
        i++;
        while (str[i])
        {
            if (ft_isdigit(str[i]) != 1)
                return (0);
            i++;
        }
        if (ft_strlen(str) == i)
            return (1);
    }
    else if (ft_strlen(str) == 1 && str[i] == '-')
        return 0;
    else if (str[i] != '-')
        while (str[i])
        {
            if (ft_isdigit(str[i]) != 1)
                return (0);
            i++;
        }
    return (1);
}