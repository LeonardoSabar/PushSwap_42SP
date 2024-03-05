/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:51 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 13:06:58 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*next;

	aux = *lst;
	if (!del || !aux)
		return ;
	while (aux)
	{
		next = aux->next;
		ft_lstdelone(aux, del);
		aux = next;
	}
	*lst = NULL;
}
