/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 19:12:02 by leobarbo         ###   ########.fr       */
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
	t_stack	*next;
	t_stack	*prev;
	int		value;
	int		position;
}	t_stack;

typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
}	t_push;

void	args_validation(char **args, t_stack push);
int		validation(int arg_nbr, char **args, t_stack push);

#endif
