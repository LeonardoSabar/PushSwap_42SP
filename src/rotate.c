/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:39:35 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/11 17:38:18 by leobarbo         ###   ########.fr       */
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
