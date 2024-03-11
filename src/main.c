/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/11 17:39:51 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		push;
	t_element	*tmp;


	validation(argc, argv, &push);
	stack_build(&push, argv);
	compare(&push);
	rotate(&push.stacks.stack_b);

	tmp = NULL;
	ft_printf("\n----------STACK_A-----------\n");
	if (push.stacks.stack_a)
		tmp = push.stacks.stack_a->first;
	while (tmp)
	{
		ft_printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	ft_printf("\n----------STACK_B-----------\n");
	if (push.stacks.stack_b)
		tmp = push.stacks.stack_b->first;
	while (tmp)
	{
		ft_printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	free_stack(&push.stacks.stack_a);
	free_stack(&push.stacks.stack_b);
	return (0);
}
