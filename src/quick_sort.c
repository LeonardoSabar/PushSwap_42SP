/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:42:18 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 12:22:09 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_push **push)
{
	set_sizes(push);
	while ((*push)->stacks.stack_a->size > 5)
	{
		while (exist_rank((*push)->stacks.stack_a, ((*push)->pivots.big_pivot) \
		&& ((*push)->stacks.stack_a->size > 5)))
		{
			if ((*push)->stacks.stack_a->first->rank \
			< (*push)->pivots.big_pivot)
			{
				pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
				if (((*push)->stacks.stack_b->size > 1) \
				&& ((*push)->stacks.stack_b->first->rank \
				< (*push)->small_pivot))
				{
					if ((*push)->stacks.stack_a->first->rank \
					> (*push)->pivots.small_pivot)
						rr(&(*push)->stacks.stack_a, \
						&(*push)->stacks.stack_b, 1);
					else
						rb(&(*push)->stacks.stack_b, 1);
				}
			}
			else
				ra(&(*push)->stacks.stack_a, 1);
		}
		if (exist_rank((*push)->stacks.stack_a, (*push)->pivots.big_pivot) == 0)
		{
			(*push)->pivots.small_pivot \
			+= (*push)->pivots.stack_size / ((*push)->pivots.chunk / 2);
			(*push)->pivots.big_pivot \
			+= (*push)->pivots.stack_size / ((*push)->pivots.chunk / 2);
		}
	}
	sort(*push);
	set_b_to_a(push);
}

void	set_b_to_a(t_push **push)
{
	int	big_pivot;
	int	small_pivot;
	int	n;
	int	size;
	int	cost;

	n = 2;
	size = (*push)->stacks.stack_b->size;
	big_pivot = size - size / (22 / n);
	small_pivot = size - size / (22 / n + 3);
	while ((*push)->stacks.stack_b->size != 0)
	{
		while (next_exist_rank((*push)->stacks.stack_b, big_pivot))
		{
			if ((*push)->stacks.stack_b->last->rank > (*push)->stacks.stack_b->first->rank)
				rrb(&(*push)->stacks.stack_b, 1);
			calculate_cost(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
			print_stack((*push)->stacks.stack_a, (*push)->stacks.stack_b);
			get_cheap_cost(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b);
			cost = min_value_rank((*push)->stacks.stack_a, (*push)->stacks.stack_b->first->rank);
			// fprintf(stderr, "(%i)\n", cost);
			// if (cost < ((int)(SIZE_A) / 2))
			// 	ra(&(*push)->stacks.stack_a, cost);
			// else
			// 	rra(&(*push)->stacks.stack_a, SIZE_A - cost);
			pa(&(*push)->stacks.stack_b, &(*push)->stacks.stack_a, 1);
		}
		if ((*push)->stacks.stack_b->first && (*push)->stacks.stack_b->first->rank < small_pivot && ((*push)->stacks.stack_b->last->rank < small_pivot))
		{
			n += 2;
			big_pivot = size - size / (22 / n);
			small_pivot = size - size / (22 / n + 3);
		}
	}
	rotate_until_sort((*push)->stacks.stack_a);
}

void	sorting_a(t_push **push)
{
	int	iterations;
	int	rrbs;

	iterations = (*push)->stacks.stack_a->size;
	while ((*push)->stacks.stack_a->size > 5)
	{
		(*push)->big_pivot = ((max_value((*push)->stacks.stack_a) + min_value((*push)->stacks.stack_a)) / 2);
		(*push)->small_pivot = (((*push)->big_pivot + min_value((*push)->stacks.stack_a)) / 2);
		iterations = (*push)->stacks.stack_a->size;
		rrbs = 0;
		while (iterations-- && (*push)->stacks.stack_a->size > 5)
		{
			if ((*(int *)(*push)->stacks.stack_a->first->next->content) < (*(int *)(*push)->stacks.stack_a->first->content) \
			&& ((*(int *)(*push)->stacks.stack_a->first->next->content) < (*push)->big_pivot))
				sa(&(*push)->stacks.stack_a, 1);
			if ((*(int *)(*push)->stacks.stack_a->first->content) < (*push)->big_pivot)
				pb(&(*push)->stacks.stack_a, &(*push)->stacks.stack_b, 1);
			if ((*(int *)(*push)->stacks.stack_b->first->content) > (*push)->small_pivot)
			{
				rb(&(*push)->stacks.stack_b, 1);
				rrbs++;
			}
			else
				ra(&(*push)->stacks.stack_a, 1);
		}
		while (rrbs--)
			rrb(&(*push)->stacks.stack_b, 1);
	}
}

void	print_stack(t_dolist *a, t_dolist *b)
{
	t_element	*aux;
	(void)a;
	aux = a->first;
	fprintf(stderr, "\n\n");
	fprintf(stderr, "|----------|\n");
	fprintf(stderr, "| stack a: |\n");
	fprintf(stderr, "|-------|--|-----------|--------|--------|----------------|\n");
	fprintf(stderr, "| value | sorted index | cost_a | cost_b |      next      |\n");
	fprintf(stderr, "|-------|--------------|--------|--------|----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %6d | %6d | %14p |\n", *((int *)aux->content), aux->rank, aux->cost_a, aux->cost_b, aux->next);
		aux = aux->next;
	}
	fprintf(stderr, "|-------|--------------|--------|--------|----------------|\n\n");
	aux = b->first;
	fprintf(stderr, "|----------|\n");
	fprintf(stderr, "| stack b: |\n");
	fprintf(stderr, "|-------|--|-----------|--------|--------|----------------|\n");
	fprintf(stderr, "| value | sorted index | cost_a | cost_b |      next      |\n");
	fprintf(stderr, "|-------|--------------|--------|--------|----------------|\n");
	while (aux)
	{
		fprintf(stderr, "| %5d | %12d | %6d | %6d | %14p |\n", *((int *)aux->content), aux->rank, aux->cost_a, aux->cost_b, aux->next);
		aux = aux->next;
	}
	fprintf(stderr, "|-------|--------------|--------|--------|----------------|\n");
	fflush(stderr);
}
