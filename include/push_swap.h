/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:13 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/05 16:55:33 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/includes/ft_printf.h"


# define PARAMETERS_MSG "Erro\n Two or more parameters are required\n"
# define INVALID_MSG "Invalid argument\n"

void	args_validation(char **args);
int		validation(int arg_nbr, char **args);

#endif
