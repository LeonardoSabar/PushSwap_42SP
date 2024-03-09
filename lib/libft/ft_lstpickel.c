/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpickel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:16:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 15:16:19 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lstpickel(t_dolist *lst, int index)
{
	t_element	*el;

	if ((!lst) || (index < 0 && - index > (int)lst->size)
		|| (index >= 0 && index + 1 > (int)lst->size))
		return (NULL);
	if (index < 0)
	{
		el = lst->last;
		while (++index)
			el = el->prev;
	}
	else
	{
		el = lst->first;
		while (index--)
			el = el->next;
	}
	return (el);
}
