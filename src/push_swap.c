/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/08 13:53:59 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc,char **argv)
{
	t_push	push;

	count_validation(argc, argv, &push);
	args_validation(argv);
	stack_build(&push, argv);
	list_to_compare(&push);
	int_compare(&push);
	return (0);
}
