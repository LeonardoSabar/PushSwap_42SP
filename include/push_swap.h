/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/06 17:41:53 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/includes/ft_printf.h"


# define PARAMETERS_MSG "Erro\n Two or more parameters are required\n"
# define INVALID_MSG "Invalid argument\n"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int		value;
	int		position;
	struct s_stack	**first;
	struct s_stack	**last;

}	t_stack;

typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//Tentar colocar o first e last aqui!
	int		size;
	int		*array;
}	t_push;

int		args_validation(char **args, t_push *push);
int		validation(int arg_nbr, char **args, t_push *push);
void	stack_build(t_push *stack, char **argv);
int		int_compare(t_push *stack);
int		list_to_compare(t_push *stack);

#endif
