//
// Created by agloin on 03.07.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>


typedef struct  t_list
{
    int                 num;
    struct t_list       *next;
}               t_stack;


t_stack     *ft_lst_new(char **str);
t_stack     *ra_rb(t_stack  *lst);
t_stack     *rra_rrb(t_stack *lst);
void        sa_sb(t_stack *lst);
void        pb(t_stack **stack_a, t_stack **stack_b);
void        pa(t_stack **stack_a, t_stack **stack_b);
void        ss(t_stack *stack_a, t_stack *stack_b);
#endif //PUSH_SWAP_H
