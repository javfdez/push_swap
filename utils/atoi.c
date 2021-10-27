/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:17:39 by javferna          #+#    #+#             */
/*   Updated: 2021/10/27 11:42:32 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_atoi_ps(const char *str, char **inputs, t_list **stack_a)
{
	unsigned long long	nb;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		nb = nb * 10 + str[i++] - '0';
	if (nb > MAX_INT)
		free_inputs_stack(inputs, stack_a);
	return (nb * sign);
}
