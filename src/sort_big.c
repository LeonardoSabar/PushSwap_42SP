/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:36:44 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/13 15:18:33 by leobarbo         ###   ########.fr       */
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
			pb(&push->stacks.stack_a, &push->stacks.stack_b);
			if (push->stacks.stack_b->size > 1 && (*(int *)push->stacks.stack_b->first->content) < push->small_pivot)
			{
				if ((*(int *)push->stacks.stack_a->first->content) > push->big_pivot)
					rr(&push->stacks.stack_a, &push->stacks.stack_b);
				else
					rb(&push->stacks.stack_b);
			}
		}
		else
			ra(&push->stacks.stack_a);
	}
}
