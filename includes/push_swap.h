//
// Created by agloin on 03.07.2020.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct  t_list
{
    int                 num;
    struct t_list       *next;
}               t_stack;

typedef struct  n_list
{
    int         max_in_stack_a;
    int         min_in_stack_a;
    int         midiana;
}               num_list;

int         find_command(char *line, t_stack **stack_a, t_stack **stack_b);
t_stack     *ft_lst_new(char **str);
void        ra_rb(t_stack  **lst);
void        rra_rrb(t_stack **stack);
void        rrr(t_stack **stack_a, t_stack **stack_b);
void        sa_sb(t_stack *lst);
void        pb(t_stack  **stack_a, t_stack  **stack_b);
void        pa(t_stack  **stack_a, t_stack  **stack_b);
void        ss(t_stack  *stack_a,  t_stack  *stack_b);
void        rr(t_stack  **stack_a, t_stack  **stack_b);
int         is_digit(char **argv);
int         is_repeat(char **argv);
int         check_ascending_oder(t_stack *stack, t_stack *stack_b);
void        fill_stack(t_stack **stack_a, char **argv);

#endif
