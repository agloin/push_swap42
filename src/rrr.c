#include "../includes/push_swap.h"

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
    {
        rra_rrb(stack_a);
        rra_rrb(stack_b);
    }
}
