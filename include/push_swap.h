/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/12 09:29:43 by leobarbo         ###   ########.fr       */
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

typedef struct s_push
{
	t_stack	stacks;
	int		*array;
}			t_push;

typedef enum e_type
{
	INPUT,
	OUTPUT,
	ERROR,
}	t_type;

long	ft_atol(const char *str);
int		build_list(t_push *push);
int		ft_isspace_push(int c);
void	arg_validation(char **args);
void	validation(int arg_nbr, char **args, t_push *push);
void	stack_build(t_push *push, char **argv);
void	compare(t_push *push);
void	message_error(char *str1, char *str2);
void	free_split(char **split);
void	first_int(char arg);
void	signal_validation(char **args, int *idx, int *odx);
void	free_stack(t_dolist **stack);
void	swap_stack(t_dolist **stack);
void	create_lst(t_element *new, t_dolist **stack);
void	push_stack(t_dolist **stack_out, t_dolist **stack_in);
void	pa(t_dolist **stack_b, t_dolist **stack_a);
void	pb(t_dolist **stack_a, t_dolist **stack_b);
void	sa(t_dolist **stack_a);
void	sb(t_dolist **stack_b);
void	ss(t_dolist **stack_a, t_dolist **stack_b);
void	rotate(t_dolist **stack);
void	ra(t_dolist **stack_a);
void	rb(t_dolist **stack_b);
void	rr(t_dolist **stack_a, t_dolist **stack_b);
void	rotate_reverse(t_dolist **stack);
void	rra(t_dolist **stack_a);
void	rrb(t_dolist **stack_b);
void	rrr(t_dolist **stack_a, t_dolist **stack_b);

#endif
