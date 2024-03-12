/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rever.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:39:31 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/12 09:36:16 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse(t_dolist **stack)
{
	t_element	*tmp;

	if (!(*stack) || !(*stack)->last || !(*stack)->first)
		return ;
	tmp = (*stack)->last;
	ft_lstpop((*stack), (*stack)->size - 1);
	ft_dolstadd_front(stack, tmp);
}

void	rra(t_dolist **stack_a)
{
	rotate_reverse(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_dolist **stack_b)
{
	rotate_reverse(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_dolist **stack_a, t_dolist **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	ft_printf("rrr\n");
}
