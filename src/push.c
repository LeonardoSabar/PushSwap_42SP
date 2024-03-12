/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:39:28 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/12 15:08:43 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_dolist **stack_out, t_dolist **stack_in)
{
	t_element	*tmp;

	if (!(*stack_out) || !(*stack_out)->first)
		return ;
	tmp = (*stack_out)->first;
	ft_lstpop((*stack_out), 0);
	if (!(*stack_in))
		create_lst(tmp, stack_in);
	else
		ft_dolstadd_front(stack_in, tmp);
}

void	pa(t_dolist **stack_b, t_dolist **stack_a)
{
	push_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_dolist **stack_a, t_dolist **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
