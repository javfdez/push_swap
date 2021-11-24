/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/11/24 12:23:28 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_best_moves(t_stack *stack_a, t_stack *stack_b, int node)
{
	t_stack	*rev;
	int		atop;
	int		abot;
	int		atopb;
	int		abotb;

	rev = ft_lstlast_stack(stack_a);
	abot = stack_a_rev(stack_a, node, &rev);
	atop = 0;
	while (++atop && stack_a->content >= node)
		stack_a = stack_a->next;
	atopb = TOP;
	abotb = BOT;
	atop = find_moves_b(stack_b, stack_a->content, atop, &atopb);
	abot = find_moves_b(stack_b, rev.target->content, abot, &abotb);
	if (atop <= abot)
		return (atopb);
	return (abotb);
}

static void	first_chunks(t_stack **stack_a, t_stack **stack_b, int i, int j)
{
	int	chunk;
	int	node;
	int	cnt;
	int	moves;

	chunk = -1;
	node = 0;
	cnt = 0;
	while (++chunk < (j - 1))
	{
		node += i;
		while (cnt++ < node)
		{
			moves = find_best_moves(stack_a, stack_b, node);
		}
	}
}

void	push_swap(t_stack **stack_a)
{
	int		i;
	int		j;
	t_stack	*stack_b;

	i = ft_lstsize_stack(*stack_a);
	index_stack(stack_a, i);
	j = (3 * i + 700) / 200;
	i /= j;
	first_chunks(stack_a, &stack_b, i, j);
	last_chunk(); //faltaria el ultimo nodo
}
