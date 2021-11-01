/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:16:08 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 09:47:04 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_swap(t_list **stack)
{
	int	aux;

	aux = *(int *)(*stack)->content;
	*(int *)(*stack)->content = *(int *)(*stack)->next->content;
	*(int *)(*stack)->next->content = aux;

}

void	swap(t_list **stack_a, t_list **stack_b, int ab)
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
