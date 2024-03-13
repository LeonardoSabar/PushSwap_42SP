/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:10:36 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/13 14:23:46 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_push *push)
{
	int	min;
	t_element	*tmp;

	min = *((int *)push->stacks.stack_a->first->content);
	tmp = push->stacks.stack_a->first;
	while (tmp)
	{
		if (*((int *)tmp->content) < min)
			min = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max_value(t_push *push)
{
	int	max;
	t_element	*tmp;

	max =  *((int *)push->stacks.stack_a->first->content);
	tmp = push->stacks.stack_a->first;
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
	push->min_value = min_value(push);
	push->max_value = max_value(push);
	push->big_pivot = (push->max_value + push->min_value) / 2;
	push->small_pivot = (push->min_value + push->big_pivot) / 2;
	ft_printf("\nmin: %d\n", push->min_value);
	ft_printf("\nmax: %d\n", push->max_value);
	ft_printf("\nbig pivot: %d\n", push->big_pivot);
	ft_printf("\nbig pivot: %d\n", push->small_pivot);
}
