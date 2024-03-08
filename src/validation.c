/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/08 11:15:19 by leobarbo         ###   ########.fr       */
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

int	list_to_compare(t_push *stack)
{
	int	idx;
	t_stack	*tmp;

	tmp = stack->first_a;
	stack->array = malloc(sizeof(int) * stack->size);
	if (!stack->array)
		return (1);
	idx = 0;
	while (tmp)
	{
		stack->array[idx] = tmp->value;
		tmp = tmp->next;
		idx++;
	}
	return (0);

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
			if (!ft_isdigit(args[idx][odx]) && !ft_isspace(args[idx][odx]))
					message_error(NOT_INT, &args[idx][odx]);
			if (ft_isdigit(args[idx][odx]) && !ft_isdigit(args[idx][odx + 1]) && !ft_isspace(args[idx][odx + 1]) && args[idx][odx + 1] != '\0')
				message_error(NOT_INT, args[idx]);
			// if (!ft_isdigit(args[idx][odx + 1]) && !ft_isspace(args[idx][odx + 1]) && args[idx][odx + 1] != '\0')
			// 	message_error(NOT_INT, args[idx]);
		}
	}
}

void validation(int arg_nbr, char **args, t_push *push)
{
	push->size = 0;
	push->stack_a = NULL;
	push->stack_b = NULL;
	if (arg_nbr < 2)
		message_error(PARAMETERS_MSG, "");
	args_validation(args);
}

void	message_error(char *str1, char *str2)
{
	ft_putstr_fd("Push_swap: ", ERROR);
	ft_putstr_fd(str1, ERROR);
	ft_putendl_fd(str2, ERROR);
	exit(EXIT_FAILURE);
}
