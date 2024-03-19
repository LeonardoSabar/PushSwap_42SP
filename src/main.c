/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 14:59:11 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push		push;

	validation(argc, argv, &push);
	stack_build(&push, argv);
	compare(&push);
	rank_linked_list(&push.stacks);
	sort(&push);
	lst_clear(&push.stacks.stack_a);
	lst_clear(&push.stacks.stack_b);
	return (0);
}

void	print_list(t_dolist *lst)
{
	t_element	*tmp;

	tmp = lst->first;
	while (tmp)
	{
		ft_printf("\n%d: ", *((int *)tmp->content));
		ft_printf("%d\n", tmp->rank);
		tmp = tmp->next;
	}
}
