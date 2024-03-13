/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/13 10:55:37 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_validation(t_dolist **stack, t_push *push)
{
	int			tmp_value;
	t_element	*tmp_node_curr;
	t_element	*tmp_node;

	if (!(*stack))
		return (-1);
	tmp_node = (*stack)->first;
	while (tmp_node)
	{
		tmp_value = *((int *)tmp_node->content);
		tmp_node_curr = tmp_node;
		while (tmp_node_curr)
		{
			if (tmp_value > *((int *)tmp_node_curr->content))
			return (0);
			tmp_node_curr = tmp_node_curr->next;
		}
		tmp_node = tmp_node->next;
	}
	if (!push->stacks.stack_b)
	{
		free_stack(stack);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	signal_validation(char **args, int *idx, int *odx)
{
	while (args[*idx][*odx] == '-')
	{
		if (!ft_isdigit(args[*idx][(*odx) + 1])
			&& !(args[*idx][(*odx) + 1] == '-'))
			message_error(NOT_INT, args[*idx]);
		(*odx)++;
	}
	while (args[*idx][*odx] == '+')
	{
		if (!ft_isdigit(args[*idx][(*odx) + 1])
			&& !(args[*idx][(*odx) + 1] == '+'))
			message_error(NOT_INT, args[*idx]);
		(*odx)++;
	}
	if (!ft_isdigit(args[*idx][*odx])
		&& !ft_isspace_push(args[*idx][*odx])
		&& args[*idx][*odx] != '\0')
		message_error(NOT_INT, &args[*idx][*odx]);
}

void	arg_validation(char **args)
{
	int	idx;
	int	odx;

	idx = 0;
	while (args[++idx])
	{
		odx = -1;
		while (args[idx][++odx])
		{
			signal_validation(args, &idx, &odx);
			if (ft_isdigit(args[idx][odx]) && !ft_isdigit(args[idx][odx + 1])
				&& !ft_isspace_push(args[idx][odx + 1])
				&& args[idx][odx + 1] != '\0')
				message_error(NOT_INT, args[idx]);
			if (ft_atol(args[idx]) > INT_MAX || ft_atol(args[idx]) < INT_MIN)
				message_error(INT_OVERFLOW, args[idx]);
		}
	}
}

void	validation(int arg_nbr, char **args, t_push *push)
{
	int	idx;
	int	odx;

	push->stacks.stack_a = NULL;
	push->stacks.stack_b = NULL;
	idx = 0;
	if (arg_nbr < 2)
		message_error(PARAMETERS_MSG, "");
	while (args[++idx])
	{
		if (ft_strlen(args[idx]) == 0 && (args[idx][0] == '\0'))
			message_error(INVALID_MSG, args[idx]);
		odx = -1;
		while (args[idx][++odx] == ' ')
			if (args[idx][odx + 1] == '\0')
				message_error(EMPTY_ARRAY, args[idx]);
	}
	arg_validation(args);
}
