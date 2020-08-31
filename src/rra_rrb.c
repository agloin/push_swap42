#include "../includes/push_swap.h"

t_stack   *rra_rrb(t_stack *lst)
{
    t_stack     *begin;
    t_stack     *tmp;

    begin = lst;
    /*
     * пролистываем до последнего листа
     */
    while (lst->next->next)
    {
        lst = lst->next;
    }
    /*
     * предпоследгий элемент
     */
    tmp = lst;
    while (lst->next)
    {
        lst = lst->next;
    }
    /*
     * ниже последний элемент мтал казваьб на первый.
     * Предпоследний на NULL;
     */
    lst->next = begin;
    tmp->next = NULL;
    return (lst);
}
