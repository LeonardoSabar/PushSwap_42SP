/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:40 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 16:55:45 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_validation(char **args)
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
			if (ft_isspace(args[idx][odx]) && ft_isspace(args[idx][odx + 1]))
			odx++;
		}
		idx++;
	}

}

int	validation(int arg_nbr, char **args)
{
	if (arg_nbr < 2)
		return (ft_putstr_fd(PARAMETERS_MSG, 2), 1);
	args_validation(args);

}
