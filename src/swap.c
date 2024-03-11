/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:01:58 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/11 16:39:46 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_dolist **stack)
{
	t_element	*tmp;

	if (!(*stack) || !(*stack)->first || !(*stack)->first->next)
		return ;
	tmp = (*stack)->first;
	ft_lstpop((*stack), 0);
	ft_lstadd_after((*stack), (*stack)->first, tmp);
}

void	sa(t_dolist **stack_a)
{
	swap_stack(stack_a);
	ft_printf("sa\n");
}

void	sb(t_dolist **stack_b)
{
	swap_stack(stack_b);
	ft_printf("sb\n");
}

void	ss(t_dolist **stack_a, t_dolist **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
}
