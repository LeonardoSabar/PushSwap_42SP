/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/11 17:42:26 by leobarbo         ###   ########.fr       */
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

int	ft_isspace_push(int c)
{
	if ((c >= 11 && c <= 13) || c == 32 || c == 9)
		return (1);
	return (0);
}
void	create_lst(t_element *new, t_dolist **stack)
{
	(*stack) = ft_calloc(1, sizeof(t_dolist));
	(*stack)->first = new;
	(*stack)->last = new;
}

void	free_stack(t_dolist **stack)
{
	if (!(*stack))
		return ;
	while ((*stack)->first->next)
	{
		(*stack)->first = (*stack)->first->next;
		free((*stack)->first->prev->content);
		free((*stack)->first->prev);
		(*stack)->first->prev = NULL;
	}
	if((*stack)->first)
		free((*stack)->first->content);
	free((*stack)->first);
	free(*stack);
}
