/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:48:11 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 12:23:41 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_sizes(t_push **push)
{
	(*push)->pivots.stack_size = (int)(*push)->stacks.stack_a->size;
	if ((*push)->stacks.stack_a->size > 200)
		(*push)->pivots.chunk = 20;
	else if ((*push)->stacks.stack_a->size > 15)
		(*push)->pivots.chunk = 6;
	else
		(*push)->pivots.chunk = 2;
	if ((*push)->pivots.chunk > 4)
	{
		(*push)->pivots.small_pivot = (int)(*push)->stacks.stack_a->size \
		/ (*push)->pivots.chunk;
		(*push)->pivots.big_pivot = (int)(*push)->stacks.stack_a->size \
		/ ((*push)->pivots.chunk / 2);
	}
	else
	{
		(*push)->pivots.small_pivot = (int)(*push)->stacks.stack_a->size \
		/ (*push)->pivots.chunk;
		(*push)->pivots.big_pivot = ((int)(*push)->stacks.stack_a->size \
		/ (*push)->pivots.chunk + 5);
	}
}

int	value(t_dolist *stk, int n)
{
	t_element	*i;

	i = stk->first;
	while (--n > 0)
		i = i->next;
	return (i->rank);
}
