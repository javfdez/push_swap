/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:07:53 by javferna          #+#    #+#             */
/*   Updated: 2021/12/03 19:55:28 by javferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	do_moves(t_stack **stack_a, t_stack **stack_b, int node, int moves)
{
	if (moves == TOPATOPB)
		topatopb(stack_a, stack_b, node, maxmin_up_check(0, 0, CHECK));
	if (moves == TOPABOTB)
		topabotb(stack_a, stack_b, node, maxmin_up_check(0, 0, CHECK));
	if (moves == BOTATOPB)
		botatopb(stack_a, stack_b, node, maxmin_up_check(0, 0, CHECK));
	if (moves == BOTABOTB)
		botabotb(stack_a, stack_b, node, maxmin_up_check(0, 0, CHECK));
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
	atop = 0;
	while (stack_a->content >= node)
	{
		stack_a = stack_a->next;
		atop++;
	}
	atopb = TOP;
	abotb = BOT;
	atop = find_moves_b(stack_b, stack_a->content, atop, &atopb); //fix this for more than 100 numbers
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

	chunk = 1;
	node = 0;
	cnt = 0;
	while (chunk < (bl - 1))
	{
		node += size;
		while (cnt < node && *stack_a)
		{
			moves = find_best_moves(*stack_a, *stack_b, node);
			do_moves(stack_a, stack_b, node, moves);
			cnt++;
		}
		chunk++;
	}
}

static int	is_ordered(t_stack *stack_a)
{
	while (stack_a->next && stack_a->next->content - stack_a->content == 1)
		stack_a = stack_a->next;
	if (!stack_a->next)
		return (1);
	return (0);
}

void	push_swap(t_stack **stack_a)
{
	int		total_size;
	int		size;
	int		bl;
	t_stack	*stack_b;

	stack_b = NULL;
	total_size = ft_lstsize_stack(*stack_a);
	index_stack(stack_a, total_size);
	if (is_ordered(*stack_a))
		return ;
	if (total_size >= 100)
	{
		bl = ((3 * total_size) + 700) / 200;
		size = total_size / bl;
		first_chunks(stack_a, &stack_b, size, bl);
		first_chunks(stack_a, &stack_b, total_size, ONECHUNK);
	}
	else
		first_chunks(stack_a, &stack_b, total_size, ONECHUNK);
	push_back(stack_a, &stack_b);
}
