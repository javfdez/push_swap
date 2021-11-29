/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/11/29 20:26:36 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_moves(t_stack **stack_a, t_stack **stack_b, int node, int moves)
{
	if (moves == TOPATOPB)
		topatopb(stack_a, stack_b, node, maxmin_update_check(0, 0, CHECK));
	if (moves == TOPABOTB)
		topabotb(stack_a, stack_b, node, maxmin_update_check(0, 0, CHECK));
	if (moves == BOTATOPB)
		botatopb(stack_a, stack_b, node, maxmin_update_check(0, 0, CHECK));
	if (moves == BOTABOTB)
		botabotb(stack_a, stack_b, node, maxmin_update_check(0, 0, CHECK));
}

static int	find_best_moves(t_stack *stack_a, t_stack *stack_b, int node)
{
	t_stack	*rev;
	int		atop;
	int		abot;
	int		atopb;
	int		abotb;

	rev = ft_lstlast_stack(stack_a);
	abot = moves_a_bot(stack_a, node, &rev, NULL);
	atop = -1;
	while (++atop && stack_a->content >= node)
		stack_a = stack_a->next;
	atopb = TOP;
	abotb = BOT;
	atop = find_moves_b(stack_b, stack_a->content, atop, &atopb);
	abot = find_moves_b(stack_b, rev->content, abot, &abotb);
	if (atop <= abot)
		return (atopb);
	return (abotb);
}

static void	first_chunks(t_stack **stack_a, t_stack **stack_b, int size, int bl)
{
	int			chunk;
	int			node;
	int			cnt;
	int			moves;

	chunk = -1;
	node = 0;
	cnt = 0;
	while (++chunk < (bl - 1))
	{
		node += size;
		while (cnt++ < node)
		{
			moves = find_best_moves(*stack_a, *stack_b, node);
			do_moves(stack_a, stack_b, node, moves);
		} // falta ordenar el stack b y hacer los pa
	}
}

void	push_swap(t_stack **stack_a)
{
	int		size;
	int		bl;
	t_stack	*stack_b;

	stack_b = NULL;
	size = ft_lstsize_stack(*stack_a);
	index_stack(stack_a, size);
	if (size >= 100)
	{
		bl = (3 * size + 700) / 200;
		size /= bl;
		first_chunks(stack_a, &stack_b, size, bl);
		//last_chunk(); //faltaria el ultimo nodo // falta que no mueva los que están organizados
	}
	else // tener en cuenta si me mandan un solo numero o 2 o más pero que ya estén ordenados
		first_chunks(stack_a, &stack_b, size, ONECHUNK);
	ft_lstclear_stack(&stack_b);
}
