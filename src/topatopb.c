/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topatopb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:25:31 by javferna          #+#    #+#             */
/*   Updated: 2021/11/24 18:46:48 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	topatopb(t_stack **stack_a, t_stack **stack_b, int node, t_maxmin *mm)
{
	int	atop;
	int	btop;
	int value;

	atop = moves_a_top(*stack_a, node, &value);
	btop = 0;
	if (counter_empty_b(stack_b, mm, value))
		btop = moves_b_top(*stack_b, mm, value); //mirar esta función y la bot porque si el content es el max y el value es mayor y estamos al comienzo del stack el cnt tiene que quedarse en 0 no en 1
	while (atop > 0 && btop > 0)
	{
		rotate(stack_a, stack_b, RR);
		atop--;
		btop--;
	}
	while (atop > 0)
	{

	}
}
