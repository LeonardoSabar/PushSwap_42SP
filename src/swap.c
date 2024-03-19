/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:01:58 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 14:41:34 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_dolist **lst)
{
	t_element	*tmp;

	if (!(*lst) || !(*lst)->first || !(*lst)->first->next)
		return ;
	tmp = (*lst)->first;
	ft_lstpop((*lst), 0);
	ft_lstadd_after((*lst), (*lst)->first, tmp);
}

void	sa(t_dolist **stack_a, int count)
{
	while (count--)
	{
		ft_swap(stack_a);
		ft_printf("sa\n");
	}
}

void	sb(t_dolist **stack_b, int count)
{
	while (count--)
	{
		ft_swap(stack_b);
		ft_printf("sb\n");
	}
}

void	ss(t_dolist **stack_a, t_dolist **stack_b, int count)
{
	while (count--)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		ft_printf("ss\n");
	}
}
