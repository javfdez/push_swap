/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:20:04 by javferna          #+#    #+#             */
/*   Updated: 2021/11/09 17:55:28 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	i = ft_lstsize_stack(*stack_a);
	index_stack(stack_a, i);

}
