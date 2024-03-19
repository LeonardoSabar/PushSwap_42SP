/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:25:31 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 11:19:57 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_linked_list(t_stack *stack)
{
	t_element	*tmp;
	int			rank;
	int			value;

	value = min_value(stack->stack_a);
	tmp = stack->stack_a->first;
	rank = 1;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
		{
			tmp->rank = rank;
			rank++;
			value = min_value_rank(stack->stack_a, value);
			tmp = stack->stack_a->first;
		}
		else
			tmp = tmp->next;
	}
}

int	min_value_rank(t_dolist *stk, int value)
{
	int			min;
	t_element	*tmp;

	if (!stk)
		return (-1);
	tmp = stk->first;
	min = __INT_MAX__;
	while (tmp)
	{
		if (*((int *)tmp->content) < min && *((int *)tmp->content) > value)
			min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	next_min_value_rank(t_dolist *stk, int value)
{
	int			min;
	t_element	*tmp;

	if (!stk)
		return (-1);
	tmp = stk->first;
	min = __INT_MAX__;
	while (tmp)
	{
		if (tmp->rank < min && tmp->rank > value)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

int	exist_rank(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank < rank)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	next_exist_rank(t_dolist *stack, int rank)
{
	t_element	*temp;
	int			count;

	count = 0;
	temp = stack->first;
	while (temp)
	{
		if (temp->rank > rank)
			count++;
		temp = temp->next;
	}
	return (count);
}
