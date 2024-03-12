/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:39:35 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/12 09:24:31 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_dolist **stack)
{
	t_element	*tmp;

	if (!(*stack) || !(*stack)->first)
		return ;
	tmp = (*stack)->first;
	ft_lstpop((*stack), 0);
	ft_dolstadd_back(stack, tmp);
}

void	ra(t_dolist **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_dolist **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_dolist **stack_a, t_dolist **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
