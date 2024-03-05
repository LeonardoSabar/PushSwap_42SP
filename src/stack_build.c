/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:20:17 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 19:19:33 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_build(t_push *stack, char **argv)
{
	t_stack	*new;
	int		idx;
	int		odx;
	char	**args;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	idx = 1;
	odx = 0;
	while (argv[idx])
		{
			args = ft_split(argv[idx], ' ');
			while (args[odx])
			{
				new->value = ft_atoi(args[odx]);
				new->next = NULL;
				new->prev = NULL;
				if (!stack->stack_a)
					stack->stack_a = new;
				else
				{
					new->prev = stack->stack_a;
					stack->stack_a->next = new;
					stack->stack_a = new;
				}
				odx++;
			}
			idx++;
		}
	else
	{
		new->prev = stack->stack_a;
		stack->stack_a->next = new;
		stack->stack_a = new;
	}
}
