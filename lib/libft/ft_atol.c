/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:03 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 18:23:14 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long	value;
	long	idx;
	int		h;

	value = 0;
	idx = 0;
	h = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
	{
		h = -1;
		while (str[idx] == '-')
			idx++;
	}
	if (str[idx] == '+')
		while (str[idx] == '+')
			idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		value = (value * 10) + (str[idx] - '0');
		idx++;
	}
	value = value * h;
	return (value);
}
