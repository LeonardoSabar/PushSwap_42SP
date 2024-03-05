/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:16 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 18:06:54 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc,char **argv)
{
	t_stack	push;

	printf("Welcome to Push_Swap\n");
	validation(argc, argv, push);
	stack_build(&push, argv);
	return (0);
}
