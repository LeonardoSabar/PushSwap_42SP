/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:10:36 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 11:19:31 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_dolist *stack)
{
	int			min;
	t_element	*tmp;

	tmp = stack->first;
	min = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
		min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max_value(t_dolist *stack)
{
	int			max;
	t_element	*tmp;

	if (!stack)
		return (-1);
	tmp = stack->first;
	max = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) > max)
		max = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

void	get_pivots(t_push *push)
{
	push->min_value = min_value(push->stacks.stack_a);
	push->max_value = max_value(push->stacks.stack_a);
	push->big_pivot = (push->max_value + push->min_value) / 2;
	push->small_pivot = (push->min_value + push->big_pivot) / 2;
}
