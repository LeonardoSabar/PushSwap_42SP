/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/13 11:20:25 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		push;



	validation(argc, argv, &push);
	stack_build(&push, argv);
	compare(&push);
	// ft_printf("\nAQUI DEU SEG FAULT\n");
	get_pivots(&push);
	sort(&push);
	free_stack(&push.stacks.stack_a);
	free_stack(&push.stacks.stack_b);
	return (0);
}

void	print_results(t_push *push)
{
	t_element	*tmp;

	tmp = NULL;
	ft_printf("\n----------STACK_A-----------\n");
	if (push->stacks.stack_a)
		tmp = push->stacks.stack_a->first;
	while (tmp)
	{
		ft_printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}
	ft_printf("\n----------STACK_B-----------\n");
	if (push->stacks.stack_b)
		tmp = push->stacks.stack_b->first;
	while (tmp)
	{
		ft_printf("%d\n", *((int *)tmp->content));
		tmp = tmp->next;
	}

}
