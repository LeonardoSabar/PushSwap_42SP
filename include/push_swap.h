/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/08 16:49:00 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define PARAMETERS_MSG "Two or more parameters are required"
# define INVALID_MSG "Invalid argument"
# define INT_DUPLICATED "Duplicated number: "
# define NOT_INT "Not a valid number: "
# define INT_OVERFLOW "Number overflow"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				position;
}	t_stack;

typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*first_a;
	t_stack	*last_a;
	t_stack	*first_b;
	t_stack	*last_b;
	int		size;
	int		*array;
}	t_push;

typedef enum e_exit
{
	SUCCESS,
	FAILURE,
}	t_exit;

typedef enum e_type
{
	INPUT,
	OUTPUT,
	ERROR,
}	t_type;

void	args_validation(char **args);
void	count_validation(int arg_nbr, char **args, t_push *push);
void	stack_build(t_push *stack, char **argv);
void	int_compare(t_push *stack);
int		list_to_compare(t_push *stack);
void	message_error(char *str1, char *str2);

#endif
