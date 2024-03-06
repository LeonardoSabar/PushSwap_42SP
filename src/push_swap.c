/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/06 16:53:22 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc,char **argv)
{
	t_push	push;

	push.size = 0;
	push.stack_a = NULL;
	push.stack_b = NULL;
	validation(argc, argv, &push);
	stack_build(&push, argv);
	list_to_compare(&push);
	int i = int_compare(&push);
	printf("%d\n", i);
	return (0);
}
