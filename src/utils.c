/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/19 21:31:25 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_line(char c)
{
	return (c == 9 || (c >= 11 && c <= 13) || c == ' ');
}

void	create_lst(t_element *new, t_dolist **stack)
{
	(*stack) = ft_calloc(1, sizeof(t_dolist));
	(*stack)->first = new;
	(*stack)->last = new;
	(*stack)->size++;
}

void	lst_clear(t_dolist **lst)
{
	if (!(*lst))
		return ;
	while ((*lst)->first && (*lst)->first->next)
	{
		(*lst)->first = (*lst)->first->next;
		free((*lst)->first->prev->content);
		free((*lst)->first->prev);
		(*lst)->first->prev = NULL;
	}
	if ((*lst)->first)
		free((*lst)->first->content);
	free((*lst)->first);
	free(*lst);
}

int	value(t_dolist *stk, int n)
{
	t_element	*i;

	i = stk->first;
	while (--n > 0)
		i = i->next;
	return (i->rank);
}

int	abs_math(int value)
{
	if (value > 0)
		return (value);
	else
		return (-value);
}

void	ft_error(char *str1, char *str2, char *str3)
{
	(void) str1;
	(void) str2;
	(void) str3;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
