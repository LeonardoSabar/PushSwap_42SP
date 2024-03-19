/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 12:24:08 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define PARAMETERS_MSG "Two or more parameters are required"
# define INVALID_MSG "Invalid argument"
# define INT_DUPLICATED "Duplicated number: "
# define NOT_INT "Not a valid number: "
# define INT_OVERFLOW "Number overflow: "
# define EMPTY_ARRAY "Invaldid. Empty argument!"

typedef struct s_stack
{
	t_dolist	*stack_a;
	t_dolist	*stack_b;
}				t_stack;

typedef struct s_pivot
{
	int		big_pivot;
	int		small_pivot;
	int		stack_size;
	int		chunk;
}			t_pivot;


typedef struct s_push
{
	t_stack	stacks;
	int		*array;
	int		max_value;
	int		min_value;
	int		big_pivot;
	int		small_pivot;
	t_pivot	pivots;
}			t_push;

typedef enum e_type
{
	INPUT,
	OUTPUT,
	ERROR,
}	t_type;


int		build_list(t_push *push);
void	compare(t_push *push);

void	calculate_cost(t_dolist **stk_a, t_dolist **stk_b);
void	get_cheap_cost(t_dolist **stk_a, t_dolist **stk_b);

void	get_pivots(t_push *push);
int		min_value(t_dolist *stack);
int		max_value(t_dolist *stack);

void	quick_sort(t_push **push);
void	set_b_to_a(t_push **push);
void	sorting_a(t_push **push);
void	print_stack(t_dolist *a, t_dolist *b);

void	rank_linked_list(t_stack *stack);
int		min_value_rank(t_dolist *stk, int value);
int		next_min_value_rank(t_dolist *stk, int value);
int		exist_rank(t_dolist *stack, int rank);
int		next_exist_rank(t_dolist *stack, int rank);

void	sort_big(t_push *push);
void	rotate_until_sort(t_dolist *stk_a);

void	sort_three_rank(t_dolist *stk);
void	sort_three(t_dolist *stk);
void	sort_four(t_dolist *stk_a, t_dolist *stk_b, t_push *push);
void	sort_five(t_dolist *stk_a, t_dolist *stk_b, t_push *push);

void	sort(t_push *push);

void	stack_build(t_push *push, char **argv);

void	set_sizes(t_push **push);
int		value(t_dolist *stk, int n);

void	message_error(char *str1, char *str2);
int		abs_math(int value);
int		ft_isspace_push(int c);
void	create_lst(t_element *new, t_dolist **stack);
void	free_stack(t_dolist **stack);

int		sort_validation(t_dolist **stack, t_push *push);
void	signal_validation(char **args, int *idx, int *odx);
void	arg_validation(char **args);
void	validation(int arg_nbr, char **args, t_push *push);

void	push_stack(t_dolist **stack_out, t_dolist **stack_in);
void	pa(t_dolist **stack_b, t_dolist **stack_a, int time);
void	pb(t_dolist **stack_a, t_dolist **stack_b, int time);

void	swap_stack(t_dolist **stack);
void	sa(t_dolist **stack_a, int time);
void	sb(t_dolist **stack_b, int time);
void	ss(t_dolist **stack_a, t_dolist **stack_b, int time);

void	rotate(t_dolist **stack);
void	ra(t_dolist **stack_a, int time);
void	rb(t_dolist **stack_b, int time);
void	rr(t_dolist **stack_a, t_dolist **stack_b, int time);

void	rotate_reverse(t_dolist **stack);
void	rra(t_dolist **stack_a, int time);
void	rrb(t_dolist **stack_b, int time);
void	rrr(t_dolist **stack_a, t_dolist **stack_b, int time);




#endif
