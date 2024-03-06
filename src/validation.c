/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/06 16:49:14 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_compare(t_push *stack)
{
	int	idx;
	t_stack	**tmp;

	tmp = stack->stack_a->first;
	while (tmp && (*tmp)->next)
	{
		idx = 0;
		while (stack->array[idx])
		{
			if ((*tmp)->value == stack->array[idx])
				return (1);
			idx++;
		}
		tmp = &(*tmp)->next;
	}
	return (0);
}

int	list_to_compare(t_push *stack)
{
	int	idx;
	t_stack	**tmp;

	tmp = stack->stack_a->first;
	stack->array = malloc(sizeof(int) * stack->size);
	if (!stack->array)
		return (1);
	idx = 0;
	while (tmp && (*tmp)->next)
	{
		stack->array[idx] = (*tmp)->value;
		tmp = &(*tmp)->next;
		idx++;
	}
	return (0);

}
int	args_validation(char **args, t_push *push)
{
	int	idx;
	int	odx;

	idx = 1;
	while (args[idx])
	{
		odx = 0;
		while (args[idx][odx])
		{
			if (odx == 0 && args[idx][odx] == '-')
			{
				if (!ft_isdigit(args[idx][odx + 1]))
					return (ft_putstr_fd(INVALID_MSG, 2), 1);
			}
			else if (!ft_isdigit(args[idx][odx]) && !ft_isspace(args[idx][odx]))
				return (ft_putstr_fd(INVALID_MSG, 2), 1);
			else if (ft_isspace(args[idx][odx]))
			{
				if (ft_isspace(args[idx][odx + 1]) || args[idx + 1] == NULL)
					push->size++;
			}
			odx++;
		}
		idx++;
	}
	return (0);
}

int validation(int arg_nbr, char **args, t_push *push)
{
	if (arg_nbr < 2)
		return (ft_putstr_fd(PARAMETERS_MSG, 2), 1);
	args_validation(args, push);
	return (0);
}
