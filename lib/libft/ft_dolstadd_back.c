/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:27:01 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 19:28:08 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dolstadd_back(t_dolist **lst, t_element *new)
{
	t_element	*aux;

	aux = (*lst)->first;
	if (aux == NULL)
	{
		(*lst)->first = new;
		return ;
	}
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}
