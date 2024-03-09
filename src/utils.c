/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 15:01:06 by leobarbo         ###   ########.fr       */
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

long	ft_atol(const char *str)
{
	long	value;
	long	idx;
	int		h;

	value = 0;
	idx = 0;
	h = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
	{
		h = -1;
		while (str[idx] == '-')
			idx++;
	}
	if (str[idx] == '+')
		while (str[idx] == '+')
			idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		value = (value * 10) + (str[idx] - '0');
		idx++;
	}
	value = value * h;
	return (value);
}
int	ft_isspace_push(int c)
{
	if ((c >= 11 && c <= 13) || c == 32 || c == 9)
		return (1);
	return (0);
}
