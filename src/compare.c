/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:10:17 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 20:13:21 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare(t_push *push)
{
	int			idx;
	int			compare;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	build_list(push);
	while (tmp && tmp->next)
	{
		compare = 0;
		idx = 0;
		while (idx < (int)push->stacks.stack_a->size)
		{
			if (*((int *)tmp->content) == push->array[idx] && compare == 1)
				message_error(INT_DUPLICATED, (ft_itoa(*((int *)tmp->content))));
			else if (*((int *)tmp->content) == push->array[idx])
				compare = 1;
			idx++;
		}
		tmp = tmp->next;
	}
	free(push->array);
}

int	build_list(t_push *push)
{
	int			idx;
	t_element	*tmp;

	tmp = push->stacks.stack_a->first;
	push->array = malloc(sizeof(int) * push->stacks.stack_a->size);
	if (!push->array)
		return (1);
	idx = 0;
	while (tmp)
	{
		push->array[idx] = *((int *)tmp->content);
		tmp = tmp->next;
		idx++;
	}
	return (0);
}
