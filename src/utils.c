/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/08 13:58:38 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_error(char *str1, char *str2)
{
	ft_putstr_fd("Push_swap: ", ERROR);
	ft_putstr_fd(str1, ERROR);
	ft_putendl_fd(str2, ERROR);
	exit(EXIT_FAILURE);
}

int	list_to_compare(t_push *stack)
{
	int	idx;
	t_stack	*tmp;

	tmp = stack->first_a;
	stack->array = malloc(sizeof(int) * stack->size);
	if (!stack->array)
		return (1);
	idx = 0;
	while (tmp)
	{
		stack->array[idx] = tmp->value;
		tmp = tmp->next;
		idx++;
	}
	return (0);

}
