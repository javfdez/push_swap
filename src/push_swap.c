/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:20:04 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 13:04:20 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*aux;

	stack_b = NULL;
	aux->next = *stack_a;
	while (*stack_a)
	{
		if (check_moves(*stack_a, stack_b))
	}
}
