/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:16:08 by javferna          #+#    #+#             */
/*   Updated: 2021/11/01 01:51:32 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list **stack_a, t_list **stack_b, int ab)
{
	int	aux;

	if (ab == SA || ab == SS)
	{
		aux = *(int *)(*stack_a)->content;
		*(int *)(*stack_a)->content = *(int *)(*stack_a)->next->content;
		*(int *)(*stack_a)->next->content = aux;
		if (ab == SA)
			write(1, "sa\n", 3);
	}
	if (ab == SB || ab == SS)
	{
		aux = *(int *)(*stack_b)->content;
		*(int *)(*stack_b)->content = *(int *)(*stack_a)->next->content;
		*(int *)(*stack_b)->next->content = aux;
		if (ab == SB)
			write(1, "sb\n", 3);
	}
	if (ab == SS)
		write(1, "ss\n", 3);
}

void	rotate(t_list **stack_a, t_list **stack_b, int ab)
{

}

void	r_rotate(t_list **stack_a, t_list **stack_b, int ab)
{

}
