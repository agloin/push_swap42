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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct			s_slist
{
	int					num;
	struct s_slist		*next;
}						t_stack;

int						find_command(char *line, t_stack **stack_a,
								t_stack **stack_b);
t_stack					*ft_lst_new(char **str);
void					ra_rb(t_stack **lst);
void					rra_rrb(t_stack **stack);
void					rrr(t_stack **stack_a, t_stack **stack_b);
void					sa_sb(t_stack *lst);
void					pb(t_stack **stack_a, t_stack **stack_b);
void					pa(t_stack **stack_a, t_stack **stack_b);
void					ss(t_stack *stack_a, t_stack *stack_b);
void					rr(t_stack **stack_a, t_stack **stack_b);
int						is_digit(char **argv);
int						is_repeat(char **argv);
int						check_ascending_oder(t_stack *stack, t_stack *stack_b);
void					fill_stack(t_stack **stack_a, char **argv);
void					main_sort(t_stack **stack_a, t_stack **stack_b);
void					exec_command(char *line, t_stack **stack_a,
										t_stack **stack_b);
int						find_position(t_stack *stack, int min);
int						len_stack(t_stack *stack);
void					sort_three_nums(t_stack **stack_a, t_stack **stack_b);
void					sort_five_nums(t_stack **stack_a, t_stack **stack_b);
int						find_extremum(t_stack *stack_a, char *str);
void					final_sort(t_stack **stack, int len, int min);
int						clean_memory(t_stack **stack_a, t_stack **stack_b);
int						len_stack(t_stack *stack);
int						find_place_to_paste(t_stack *stack, int num);
int						find_last_elem(t_stack *stack);
int						find_min_operation_in_stack_b(t_stack *stack_a,
										t_stack *stack_b);
void					rotate_b(t_stack **stack_b, int actual_num);
int						one_part_stack_a(int max_in_stack_a,
										int min_in_stack_a);

#endif
