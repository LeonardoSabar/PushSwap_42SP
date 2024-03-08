/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/08 13:53:25 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_compare(t_push *stack)
{
	int	idx;
	int	compare;
	t_stack	*tmp;

	tmp = stack->first_a;
	while (tmp && tmp->next)
	{
		compare = 0;
		idx = 0;
		while (idx < stack->size)
		{
			if (tmp->value == stack->array[idx] && compare == 1)
				message_error(INT_DUPLICATED, (ft_itoa(tmp->value)));
			else if (tmp->value == stack->array[idx])
				compare = 1;
			idx++;
		}
		tmp = tmp->next;
	}
	free(stack->array);
}

void	args_validation(char **args)
{
	int	idx;
	int	odx;

	idx = 0;
	while (args[++idx])
	{
		odx = -1;
		while (args[idx][++odx])
		{
			while (args[idx][odx] == '-')
			{
				if (!ft_isdigit(args[idx][odx + 1]) && !(args[idx][odx + 1] == '-'))
					message_error(NOT_INT, args[idx]);
				odx++;
			}
			while (args[idx][odx] == '+')
			{
				if (!ft_isdigit(args[idx][odx + 1]) && !(args[idx][odx + 1] == '+'))
					message_error(NOT_INT, args[idx]);
				odx++;
			}
			if (ft_isdigit(args[idx][odx]) && !ft_isdigit(args[idx][odx + 1])
				&& !ft_isspace(args[idx][odx + 1]) && args[idx][odx + 1] != '\0')
				message_error(NOT_INT, args[idx]);
		}
	}
}

void count_validation(int arg_nbr, char **args, t_push *push)
{
	push->size = 0;
	push->stack_a = NULL;
	push->stack_b = NULL;
	const char *str = args[1];
	if (arg_nbr < 2 )
		message_error(PARAMETERS_MSG, "");
	if (arg_nbr == 2)
	{
		if (ft_strncmp(args[1], str, 1) == 0)
			message_error(INVALID_MSG, args[1]);
	}
}
