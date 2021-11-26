/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:25:31 by javferna          #+#    #+#             */
/*   Updated: 2021/11/26 11:40:15 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	botabotb(t_stack **stack_a, t_stack **stack_b, int node, t_maxmin *mm)
{
	t_stack	*rev;
	int	abot;
	int	bbot;
	int value;

	rev = ft_lstlast_stack(stack_a);
	abot = moves_a_bot(*stack_a, node, &rev, &value);
	bbot = 0;
	if (counter_empty_b(stack_b, mm, value))
		bbot = moves_b_bot(*stack_b, value, mm);
	while (abot-- > 0 && bbot-- > 0)
		rotate(stack_a, stack_b, RR);
	while (abot-- > 0)
		rotate(stack_a, NULL, RA);
	while (bbot-- > 0)
		rotate(NULL, stack_b, RB);
	push(stack_b, stack_a, PB);
}

void	botatopb(t_stack **stack_a, t_stack **stack_b, int node, t_maxmin *mm)
{
	t_stack	*rev;
	int	abot;
	int	btop;
	int value;

	rev = ft_lstlast_stack(stack_a);
	abot = moves_a_bot(*stack_a, node, &rev, &value);
	btop = 0;
	if (counter_empty_b(stack_b, mm, value))
		btop = moves_b_top(*stack_b, value, mm);
	while (abot-- > 0 && btop-- > 0)
		rotate(stack_a, stack_b, RR);
	while (abot-- > 0)
		rotate(stack_a, NULL, RA);
	while (btop-- > 0)
		rotate(NULL, stack_b, RB);
	push(stack_b, stack_a, PB);
}

void	topabotb(t_stack **stack_a, t_stack **stack_b, int node, t_maxmin *mm)
{
	int	atop;
	int	bbot;
	int value;

	atop = moves_a_top(*stack_a, node, &value);
	bbot = 0;
	if (counter_empty_b(stack_b, mm, value))
		bbot = moves_b_bot(*stack_b, value, mm);
	while (atop-- > 0 && bbot-- > 0)
		rotate(stack_a, stack_b, RR);
	while (atop-- > 0)
		rotate(stack_a, NULL, RA);
	while (bbot-- > 0)
		rotate(NULL, stack_b, RB);
	push(stack_b, stack_a, PB);
}

void	topatopb(t_stack **stack_a, t_stack **stack_b, int node, t_maxmin *mm)
{
	int	atop;
	int	btop;
	int value;

	atop = moves_a_top(*stack_a, node, &value);
	btop = 0;
	if (counter_empty_b(stack_b, mm, value))
		btop = moves_b_top(*stack_b, value, mm);
	while (atop-- > 0 && btop-- > 0)
		rotate(stack_a, stack_b, RR);
	while (atop-- > 0)
		rotate(stack_a, NULL, RA);
	while (btop-- > 0)
		rotate(NULL, stack_b, RB);
	push(stack_b, stack_a, PB);
}
