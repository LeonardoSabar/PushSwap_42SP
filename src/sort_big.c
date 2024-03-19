/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:36:44 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 12:19:35 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_push *push)
{
	int	iterations;

	iterations = push->stacks.stack_a->size;
	while (iterations--)
	{
		if ((*(int *)push->stacks.stack_a->first->content) < push->big_pivot)
		{
			pb(&push->stacks.stack_a, &push->stacks.stack_b, 1);
			if (push->stacks.stack_b->size > 1 \
			&& (*(int *)push->stacks.stack_b->first->content) \
			< push->small_pivot)
			{
				if ((*(int *)push->stacks.stack_a->first->content) \
				> push->big_pivot)
					rr(&push->stacks.stack_a, &push->stacks.stack_b, 1);
				else
					rb(&push->stacks.stack_b, 1);
			}
		}
		else
			ra(&push->stacks.stack_a, 1);
	}
	sort(push);
	set_b_to_a(&push);
}

void	rotate_until_sort(t_dolist *stk_a)
{
	int			min;
	t_element	*tmp;
	int			idx;

	tmp = stk_a->first;
	min = tmp->rank;
	idx = 0;
	while (tmp)
	{
		if (min < tmp->rank)
			min = tmp->rank;
		tmp = tmp->next;
	}
	tmp = stk_a->first;
	while (tmp && tmp->rank != min)
	{
		idx++;
		tmp = tmp->next;
	}
	idx++;
	if (min > (int)(stk_a->size / 2))
		min -= stk_a->size;
	if (min < 0)
		rra(&stk_a, abs_math(idx));
	else
		ra(&stk_a, abs_math(idx));
}
