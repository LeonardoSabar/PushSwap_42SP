/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:20:05 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/12 08:41:51 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dolstadd_front(t_dolist **lst, t_element *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst)->first;
	(*lst)->first->prev = new;
	new->prev = NULL;
	(*lst)->first = new;
	(*lst)->size++;
}
