/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 20:39:50 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_validation(char **args, t_push *push)
{
	int	idx;
	int	odx;

	idx = 1;
	while (args[idx])
	{
		odx = 0;
		while (args[idx][odx])
		{
			if (!ft_isdigit(args[idx][odx]) && !ft_isspace(args[idx][odx]))
				return (ft_putstr_fd(INVALID_MSG, 2), 1);
			if (ft_isspace(args[idx][odx]) && (ft_isspace(args[idx][odx + 1]
				|| args[idx + 1]== NULL)))
				push->size++;
			odx++;
		}
		idx++;
	}
	return (0);
}

int validation(int arg_nbr, char **args, t_push *push)
{
	if (arg_nbr < 2)
		return (ft_putstr_fd(PARAMETERS_MSG, 2), 1);
	args_validation(args, push);
	return (0);
}
