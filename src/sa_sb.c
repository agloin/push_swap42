#include "../includes/push_swap.h"


void     sa_sb(t_stack *lst)
{
    if (lst && lst->next)
        ft_swap_int(&lst->num, &lst->next->num);
}
