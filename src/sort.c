/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:24:58 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/13 14:57:26 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push *push)
{
	if (push->stacks.stack_a->size == 2)
		sa(&push->stacks.stack_a);
	else if (push->stacks.stack_a->size == 3)
		sort_three_a(push);
	else if (push->stacks.stack_a->size == 4)
		sort_four(push);
	else if (push->stacks.stack_a->size == 5)
		sort_five(push);
	else
		sort_big(push);
	print_results(push);
	sort_validation(&push->stacks.stack_a, push);
}
