/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:17:39 by javferna          #+#    #+#             */
/*   Updated: 2021/11/07 19:08:31 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_atoi_ps(const char *str, char **inputs, t_stack **stack_a)
{
	long long	nb;
	int			i;
	int			sign;

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
	nb *= sign;
	if (i > 12 || nb > MAX_INT || nb < MIN_INT)
		free_all_error(inputs, stack_a);
	return (nb);
}
