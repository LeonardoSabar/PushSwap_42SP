/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:36:02 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/13 14:30:21 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_push *push)
{
	int	max;

	max = max_value(push);
	if (*(int *)push->stacks.stack_a->first->content == max)
		ra(&push->stacks.stack_a);
	else if ((*(int *)push->stacks.stack_a->first->next->content) == max)
		rra(&push->stacks.stack_a);
	if ((*(int *)push->stacks.stack_a->first->content) >
		(*(int *)push->stacks.stack_a->first->next->content))
		sa(&push->stacks.stack_a);
}

void	sort_four(t_push *push)
{
	int	min;

	min = min_value(push);
	if (*(int *)push->stacks.stack_a->first->next->content == min)
		sa(&push->stacks.stack_a);
	else if (*(int *)push->stacks.stack_a->first->next->next->content == min)
	{
		ra(&push->stacks.stack_a);
		sa(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->content == min)
		rra(&push->stacks.stack_a);
	sort_validation(&push->stacks.stack_a, push);
	if (!sort_validation(&push->stacks.stack_a, push))
		pb(&push->stacks.stack_a, &push->stacks.stack_b);
	sort_three_a(push);
	pa(&push->stacks.stack_b, &push->stacks.stack_a);
}

void	sort_five(t_push *push)
{
	int	min;

	min = min_value(push);
	if (*(int *)push->stacks.stack_a->first->next->content == min)
		sa(&push->stacks.stack_a);
	else if (*(int *)push->stacks.stack_a->first->next->next->content == min)
	{
		rra(&push->stacks.stack_a);
		rra(&push->stacks.stack_a);
		rra(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->content == min)
	{
		rra(&push->stacks.stack_a);
		rra(&push->stacks.stack_a);
	}
	else if (*(int *)push->stacks.stack_a->first->next->next->next->next->content == min)
		rra(&push->stacks.stack_a);
	if (!sort_validation(&push->stacks.stack_a, push))
		pb(&push->stacks.stack_a, &push->stacks.stack_b);
	sort_four(push);
	pa(&push->stacks.stack_b, &push->stacks.stack_a);
}
