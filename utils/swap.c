/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:16:08 by javferna          #+#    #+#             */
/*   Updated: 2021/11/07 19:48:39 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_swap(t_stack **stack)
{
	int	aux;

	aux = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = aux;
}

void	swap(t_stack **stack_a, t_stack **stack_b, int ab)
{
	if (ab == SA)
	{
		do_swap(stack_a);
		write(1, "sa\n", 3);
	}
	if (ab == SB)
	{
		do_swap(stack_b);
		write(1, "sb\n", 3);
	}
	if (ab == SS)
	{
		do_swap(stack_a);
		do_swap(stack_b);
		write(1, "ss\n", 3);
	}
}
