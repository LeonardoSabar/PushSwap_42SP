/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:19:30 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 20:13:17 by leobarbo         ###   ########.fr       */
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
